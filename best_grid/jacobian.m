function [r,J] = jacobian(vars)
global n_func nvar n1 n2 donnees c x N
n_func
%Calcul du jacobien et de r
r = zeros(1,n_func);
nzero = 6*n1*n2+2*N;
is = zeros(1,nzero);
js = zeros(1,nzero);
vals = zeros(1,nzero);
k=1;
%Traitement des f_ij
base = 0;
for i=1:n1
    for j=1:n2
        xij = [vars(nvar-3)+(i-1)*vars(nvar-1);vars(nvar-2)+(j-1)*vars(nvar)];
        if nargout > 1
            is(k) = i*n2+j;js(k)=i*n2+j;vals(k)=norm(xij-donnees(:,c(i,j)));k=k+1;
            is(k) = i*n2+j;js(k)=nvar-3;vals(k)=vars(i*n2+j)/(norm(xij-donnees(:,c(i,j)))+eps)*(xij(1)-donnees(1,c(i,j)));k=k+1;
            is(k) = i*n2+j;js(k)=nvar-2;vals(k)=vars(i*n2+j)/(norm(xij-donnees(:,c(i,j)))+eps)*(xij(2)-donnees(2,c(i,j)));k=k+1;
            is(k) = i*n2+j;js(k)=nvar-1;vals(k)=vars(i*n2+j)/(norm(xij-donnees(:,c(i,j)))+eps)*i*(xij(1)-donnees(1,c(i,j)));k=k+1;
            is(k) = i*n2+j;js(k)=nvar;vals(k)=vars(i*n2+j)/(norm(xij-donnees(:,c(i,j)))+eps)*j*(xij(2)-donnees(2,c(i,j)));k=k+1;
        end
        r(base+(i*n2+j)) = vars(i*n2+j)*norm(xij-donnees(:,c(i,j)));
    end
end
%Traitement des g_k
base = n1*n2;
for i=1:N
    if nargout > 1
        is(k)=base+i;js(k)=base+i;vals(k)=norm(donnees(:,i)-x(:,i));k=k+1;
    end
    r(base+i) = vars(base+i)*norm(donnees(:,i)-x(:,i));
end
%Traitement des h_ij
base = base+N;
for i=1:n1
    for j=1:n2
        if nargout > 1
            is(k)=base+(i*n2+j);js(k)=i*n2+j;vals(k)=-2*vars(i*n2+j);k=k+1;
        end
        r(base+(i*n2+j)) = 1-vars(i*n2+j)^2;
    end
end
%Traitement des h'_k
base = base + n1*n2;
for i=1:N
    if nargout > 1
            %is(k)=base+i;js(k)=n1*n2+i;vals(k)=-2*sqrt(scores_final(i))*vars(n1*n2+i);k=k+1;
            is(k)=base+i;js(k)=n1*n2+i;vals(k)=-2*sqrt(vars(n1*n2+i));k=k+1;
    end
    %r(base+i) = sqrt(scores_final(i))*(1-vars(n1*n2+i)^2); 
    r(base+i) = sqrt((1-vars(n1*n2+i)^2));
end

lambda=15;
if nargout > 1

    vals(1:(5*n1*n2+N)) = lambda * vals(1:(5*n1*n2+N));
    %vals((3*(2*n1+1)*(2*n2+1)+N)+1:end) = sqrt(1-gamma)*vals((3*(2*n1+1)*(2*n2+1)+N)+1:end);
%      is
%      js
%      n_func
%      nvar
    J=sparse(is,js,vals,n_func,nvar);
end
r(1:(n1*n2+N)) = lambda* r(1:(n1*n2+N));
%r(((2*n1+1)*(2*n2+1)+N+1):end) = sqrt(1-gamma)*r(((2*n1+1)*(2*n2+1)+N+1):end);
end