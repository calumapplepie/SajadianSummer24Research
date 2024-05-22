 function [Sa, Sb, Sc, J] = fcn(Vdc, sys, Ref, If, Vc, Io, mode)

Sa = 0;
Sb = 0;
Sc = 0;

xout  = 0;
J     = 0;
J_out = 1e9;

Ts  = sys(1); 
Lf  = sys(2);
Cf  = sys(3); 
Rf  = sys(4);      % Inductor ESR 
Rc  = sys(5);

refa = Ref(1);          refb = Ref(2);
Vca   = Vc(1);         Vcb = Vc(2);
Ioa   = Io(1);           Iob = Io(2);
ILa   = If(1);            ILb = If(2);

VSI = 0; CSI = 0;  % Initialize Modes for Cost Function
Mode = VSI;        % Select Operation Mode

if mode == 0 
    VSI = 1; CSI = 0; 
elseif mode > 0
    VSI = 0; CSI = 1;
end
% disp(CSI); disp(VSI);

% A = [-R/L -1/L;1/Cf 0   ;  ...
%      Rc/Cf       0        -Rc/Cf;  ...
%      0        1/Lt    -Rt/Lt ];
% 
% B = [1/Lf; 0; 0];
% 
% D = [0 0;0 -1/Lf];
A = [-Rf/Lf -1/Lf;1/Cf 0];
B = [1/Lf 0;0 -1/Cf];

I  = eye(2);
Ad = expm(A.*Ts);
Bd = A\(Ad - I);
% Dd = inv(A)*(Ad - I)*D;

% Voltage vectors
v0 =  0;
v1 =  2/3 *Vdc;
v2 =  1/3*Vdc + 1j*sqrt(3)/3*Vdc;
v3 = -1/3*Vdc + 1j*sqrt(3)/3*Vdc;
v4 = -2/3*Vdc;
v5 = -1/3*Vdc - 1j*sqrt(3)/3*Vdc;
v6 =  1/3*Vdc - 1j*sqrt(3)/3*Vdc;
v7 =  0;
Vinv = [v0 v1 v2 v3 v4 v5 v6 v7];

states = [0 0 0; 1 0 0; 1 1 0; 0 1 0; ...
          0 1 1; 0 0 1; 1 0 1; 1 1 1];

% Avoid Error xout = 0 out of range [1,8]
% if xout == 0, xout = 1; end

for i = 1:8
    
% i-th voltage vector for current prediction
 Vinva = real(Vinv(i));  
 Vinvb = imag(Vinv(i));

% For alpha 
% x= Ad*[ILa;Vca;Ioa] + Bd*[Vinva]; + Dd*[Voa];
x= Ad*[ILa;Vca] + Bd*[Vinva;Ioa]; 
V_k1a = x(2);

% For Beta 
% y= Ad*[ILb;Vcb;Iob] + Bd*[Vinvb] + Dd*[Vob];
y= Ad*[ILb;Vcb] + Bd*[Vinvb;Iob];
V_k1b = y(2);

   

J = VSI*((refa - V_k1a)^2 + (refb - V_k1b)^2);

if ( J < J_out)
      J_out = J;
       xout = i;
end
  
end

 Sa = states(xout,1);
 Sb = states(xout,2);
 Sc = states(xout,3);
