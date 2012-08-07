clear all
close all
global donnees N n_func nvar n1 n2 ;
%% Création aléatoire des données (A MODIFIER)
n1 = 2;
n2 = 2;
dx = 0.5
dy = 0.8
N=100;
is = randi([-n1 n1],1,N);
js = randi([-n2 n2],1,N);
donnees = [dx*is 4/3*dx*is;dy*js 3/2*dy*js];
N=2*N
donnees = donnees + 0.05*randn(2,N);
% Plot des données
figure;
hold on
plot(donnees(1,:),donnees(2,:),'*r');
% Plot de la grille
points1 = [-n1*dx*ones(1,2*n2+1);dy*(-n2:n2)];
points2 = [n1*dx*ones(1,2*n2+1);dy*(-n2:n2)];
for i=1:(2*n2+1)
    plot([points1(1,i) points2(1,i)],[points1(2,i) points2(2,i)],'-b');
end
points1 = [dx*(-n1:n1);-n2*dy*ones(1,2*n1+1)];
points2 = [dx*(-n1:n1);n2*dy*ones(1,2*n1+1)];
for i=1:(2*n1+1)
    plot([points1(1,i) points2(1,i)],[points1(2,i) points2(2,i)],'-b');
end
hold off
drawnow;

%% Création aléatoire des données (à partir de points de la grille)
n1 = 3;
n2 = 4;
dx = 0.5
dy = 0.8
N=100
is = randi(n1,1,N);
js = randi(n2,1,N);
%N=n1*n2;
%is = repmat(1:n1,1,n2)
%js = reshape(repmat((1:n2)',1,n1)',[],1)'
donnees = [dx*(is-1) n1*1.05*dx+dx*(is-1);dy*(js-1) ,n2*1.1*dy+dy*(js-1)]
donnees = donnees + 0.05*randn(2,2*N);
N=2*N
% Plot des données
figure;
plot(donnees(1,:),donnees(2,:),'*r');
%% Données réelles (A MODIFIER)

data=load('rects/monge_1_rect.txt','-ASCII');
rects=data(:,1:4);
centers = [rects(:,1)+rects(:,3)/2 rects(:,2)+rects(:,4)/2 ];
k=size(rects,1);
r = randperm(k);
k=1000
N=k
donnees = centers(r(1:k),:)';
rects = rects(r(1:k),:);
% Plot des données
figure;
plot(donnees(1,:),donnees(2,:),'*r');
drawnow;  

%% Données fenetres
A = imread('test.jpg');
figure;
imshow(A)
clicks = ginput;
donnees = clicks;
N=size(donnees,2)

%% Données réelles non overlap
global scores_final
load 'monge_99for_Simon.mat'
donnees = [rects_final(:,1)+rects_final(:,3)/2 rects_final(:,2)+rects_final(:,4)/2 ]';
N=size(donnees,2)
figure;
plot(donnees(1,:),donnees(2,:),'*r');
drawnow;  
%% Normalisation des données entre 0 et 1
donnees=clicks';
maxX = max(donnees(1,:));
minX = min(donnees(1,:));
donnees(1,:) = 1/(maxX-minX)*(donnees(1,:)-minX);
maxY = max(donnees(2,:));
minY = min(donnees(2,:));
donnees(2,:) = 1/(maxY-minY)*(donnees(2,:)-minY);
% rects(:,1) = 1/(maxX-minX)*(rects(:,1)-minX);
% rects(:,3) = 1/(maxX-minX)*rects(:,3);
% rects(:,2) = 1/(maxY-minY)*(rects(:,2)-minY);
% rects(:,4) = 1/(maxY-minY)*rects(:,4);
%% Initialisation (dx et dy sont les points les plus proches sur les lignes
%% horizontales et verticales passant par l'origine)
cx = min(donnees(1,:));
cy = min(donnees(2,:));
seuil = 0.1;
a = abs(donnees(1,abs(donnees(2,:)-cy)<seuil)-cx);
b = abs(donnees(2,abs(donnees(1,:)-cx)<seuil)-cy);
dx = min(a(a>seuil))
dy = min(b(b>seuil))
% ICI A REMETTRE
n1 = 7%ceil(max(a)/dx)
n2 = 3%ceil(max(b)/dy)

alpha = ones(1,n1*n2);
beta = ones(1,N);
vars = [alpha';beta';cx;cy;dx;dy];

n_func = 2*(n1*n2+N);
nvar = n1*n2+N+4;
figure(5);
clf
hold on
for i=1:N
plot(donnees(1,i),donnees(2,i),'s','MarkerFaceColor',min(1,max(0,vars(n2*n1+i)))*ones(1,3));
end
% Plot de la grille
points1 = [cx*ones(1,n2);cy+dy*((1:n2)-1)];
points2 = [cx+(n1-1)*dx*ones(1,n2);cy+dy*((1:n2)-1)];
for i=1:n2
    plot([points1(1,i) points2(1,i)],[points1(2,i) points2(2,i)],'-b');
end
points1 = [cx+dx*((1:n1)-1);cy*ones(1,n1)];
points2 = [cx+dx*((1:n1)-1);cy+(n2-1)*dy*ones(1,n1)];
for i=1:n1
    plot([points1(1,i) points2(1,i)],[points1(2,i) points2(2,i)],'-b');
end
hold off
drawnow
%% Gauss Newton
eps = 10^(-9)
global c x
pas=1;
n_iter=5;
err = zeros(1,n_iter);
for iter=1:n_iter
    iter 
    %Calcul des donnees les plus proches des centres
    c  = zeros(n1,n2);
    for i=1:n1
        for j=1:n2
            xij = [vars(nvar-3)+(i-1)*vars(nvar-1);vars(nvar-2)+(j-1)*vars(nvar)];
            [~,ind] = min(sum((donnees - repmat(xij,1,N)).^2));
            c(i,j) = ind;
        end
    end
    c';
    %Calcul des centres les plus proches des donnees
    x = round((donnees-repmat([vars(nvar-3);vars(nvar-2)],1,N))./[vars(nvar-1)*ones(1,N);vars(nvar)*ones(1,N)]);
    x = x+1;
    x(1,x(1,:)>n1) = n1;
    x(1,x(1,:)<=0) = 1;
    x(2,x(2,:)>n2) = n2;
    x(2,x(2,:)<=0) = 1;
    x(1,:) = vars(nvar-3) + vars(nvar-1)*(x(1,:)-1);
    x(2,:) = vars(nvar-2) + vars(nvar)*(x(2,:)-1);
    optimset('Algorithm','levenberg-marquardt');
    optimset('Jacobian','on');
    optimset('MaxIter',1);
    %[vars,residual,rrr] = lsqnonlin(@jacobian,vars);
    [r,J] = jacobian(vars);
    delta = -pinv(full(J))*r';
    residual = sum(r.^2);
    vars = vars+pas*delta;
    vars(nvar-3:nvar)
    err(iter) = residual;
    
    % Plot des données
cx = vars(nvar-3);
cy=vars(nvar-2);
dx = vars(nvar-1);
dy=vars(nvar);
figure(3);
clf
hold on

for i=1:N
plot(donnees(1,i),donnees(2,i),'s','MarkerFaceColor',min(1,max(0,vars(n1*n2+i)))*ones(1,3));
end
% Plot de la grille
points1 = [cx*ones(1,n2);cy+dy*((1:n2)-1)];
points2 = [cx+(n1-1)*dx*ones(1,n2);cy+dy*((1:n2)-1)];
for i=1:n2
    plot([points1(1,i) points2(1,i)],[points1(2,i) points2(2,i)],'-b');
end
points1 = [cx+dx*((1:n1)-1);cy*ones(1,n1)];
points2 = [cx+dx*((1:n1)-1);cy+(n2-1)*dy*ones(1,n1)];
for i=1:n1
    plot([points1(1,i) points2(1,i)],[points1(2,i) points2(2,i)],'-b');
end
%show_rects
hold off
drawnow
pas=0.95*pas;
end

%% Final
figure;
hold on
imagesc(A)
points1 = [cx*ones(1,n2);cy+dy*((1:n2)-1)];
points2 = [cx+(n1-1)*dx*ones(1,n2);cy+dy*((1:n2)-1)];
for i=1:n2
    plot((maxX-minX)*[points1(1,i) points2(1,i)]+minX,(maxY-minY)*[points1(2,i) points2(2,i)]+minY,'-b');
end
points1 = [cx+dx*((1:n1)-1);cy*ones(1,n1)];
points2 = [cx+dx*((1:n1)-1);cy+(n2-1)*dy*ones(1,n1)];
for i=1:n1
     plot((maxX-minX)*[points1(1,i) points2(1,i)]+minX,(maxY-minY)*[points1(2,i) points2(2,i)]+minY,'-b');
end
%plot(1:n_iter,err);