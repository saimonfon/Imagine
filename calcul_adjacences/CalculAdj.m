clear all
close all
file = fopen('C:\Users\simon\Documents\data_olivier\points_final.txt','r')
%file =fopen('C:\Users\simon\Documents\prog_grammaires\models\hlm1.txt','r')
polygones={}
samples = {}
i=1;
maxC = zeros(1,3);
minC = zeros(1,3);
colormap(jet)
figure
hold on;
while(~feof(file))
    l = fgets(file);
    mat = sscanf(l,'%f');
    mat = reshape(mat,3,[]);
    %mat  = mat+0.05*randn(size(mat));
    X = mat(1,:);
    Y = mat(2,:);
    Z = mat(3,:);
    polygones{i}=mat;
    size(X);
   
    dt = DelaunayTri(mat');
    volumes = zeros(1,size(dt,1));
    for j=1:size(dt,1)
        p = mat(:,dt(j,:));
        volumes(j) = norm(cross(p(:,2)-p(:,1),p(:,3)-p(:,1)))+norm(cross(p(:,2)-p(:,1),p(:,4)-p(:,1)))+norm(cross(p(:,3)-p(:,1),p(:,4)-p(:,1)))+norm(cross(p(:,3)-p(:,2),p(:,4)-p(:,2)));
    end
    accumulation = cumsum(volumes);
    m=max(floor(50*volumes(j)),500);
    %m=min(floor(50*volumes(j)),500);
    points = zeros(3,m);
    rands = rand(1,m)*accumulation(end);
    for j=1:m
        index = find(accumulation>rands(j),1);
       % index=randi(size(dt,1))
        r = rand(1,3);
        s = r(1);t=r(2);u=r(3);
        if(s+t>1)
            s=1-s;
            t=1-t;
        end
        if(t+u>1)
            tmp=u;
            u=1-s-t;
            t=1-tmp;
        elseif(s+t+u>1)
            tmp=u;
            u=s+t+u-1;
            s=1-t-tmp;
        end
        a=1-s-t-u;
        points(:,j) = (mat(:,dt(index,:))*[a s t u]')';
        maxC = max(maxC,points(:,j)');
        minC = min(minC,points(:,j)');
    end
    f = fopen('samples.txt','a');
    fprintf(f,'%i\n',m);
    fclose(f);
    dlmwrite('samples.txt',points','-append','delimiter',' ');
    %patch(X,Y,Z,[1 1 1],'FaceAlpha',0.01);
    %tetramesh(dt(:,:),mat')
    %plot3(points(1,:),points(2,:),points(3,:),'*r');
    samples{i} = points;
    i=i+1
end
N=size(polygones,2)
% for i=1:N
%     mat=polygones{i};
%      X = mat(1,:);
%     Y = mat(2,:);
%     Z = mat(3,:);
%     patch(X,Y,Z,randi(200),'FaceAlpha',0.5);
%     points=samples{i};
%     plot3(points(1,:),points(2,:),points(3,:),'*r');
%     i
% end

%% Scaling des données
nb_cell = 70;
pas = max(maxC-minC)/nb_cell;
%Coin inférieur droit (0,0,0)
for i=1:size(polygones,2)
     samples{i} = samples{i} - repmat(minC',1,size(samples{i},2));
end

%% Construction de la grille
adj=zeros(N,N);
for iter=1:8
grille = zeros(nb_cell^3,size(polygones,2));
for i=1:size(polygones,2)
    for p=samples{i}
        p2=p;
        if(mod(iter,8)==0)
            p2(1) = p2(1)+pas/2;
        end
        if(iter/8 <= 0.5)
            p2(2) = p2(2)+pas/2;
        end
        if(mod(iter,4)<2)
            p2(3)=p2(3)+pas/2;
        end
        p2(p2<0) = 0;
        ind = floor(p2/pas)+1;
        grille((ind(1)-1)*nb_cell^2+(ind(2)-1)*nb_cell+ind(3),i)=1;
    end
end
N=size(polygones,2);
for i=1:nb_cell^3
   membres = find(grille(i,:)>0);
   for l=membres'
       for l2=membres'
           adj(l,l2)=1;
       end
   end
end

iter
end
adj = adj-eye(size(adj));
%% Write to file
dlmwrite('C:\Users\simon\Documents\data_olivier\adj_matlab.txt',adj,' ');
%% Plot
figure;
hold on;
for i=1:N
    mat=polygones{i}- repmat(minC',1,size(polygones{i},2));
     X = mat(1,:);
    Y = mat(2,:);
    Z = mat(3,:);
    %patch(X,Y,Z,randi(200),'FaceAlpha',0.5);
    points = samples{i};
   scatter3(points(1,:),points(2,:),points(3,:),1,mod([5 27 nb_cell]*(floor(points/pas)+1),200));
    i
end
% i = 0:(5*pas):nb_cell*pas;
% [X Y] = meshgrid(i,i);                         
% x = [X(:) X(:)]';                                
% y = [Y(:) Y(:)]';
% z = [repmat(i(1),1,length(x)); repmat(i(end),1,length(x))];
% col = 'b';
% hold on;
% plot3(x,y,z,col);                                         
% plot3(y,z,x,col);
% plot3(z,x,y,col);

% for i=1:N
%     for j=1:N
%         if(adj(i,j)>0)
%              extremites = [mean(polygones{i},2) mean(polygones{j},2)];
%              plot3(extremites(1,:),extremites(2,:),extremites(3,:),'-bs','LineWidth',2);
%              end
%     end
% end
% file2 = fopen('C:\Users\simon\Documents\data_olivier\adj_auto.txt','r');
% mat2 = fscanf(file2,'%i');
% size(mat2)
% mat2 = reshape(mat2,size(polygones,2),size(polygones,2));
% for i=1:size(polygones,2)%[mat3(2*marche) mat3(2*marche+1)]
%     for j=1:(i-1)%[mat3(2*marche) mat3(2*marche+1)]
%         if(mat2(i,j)==1)
%             extremites = [mean(polygones{i},2) mean(polygones{j},2)];
%             plot3(extremites(1,:),extremites(2,:),extremites(3,:),'-bs');
%         end
%     end
% end

% file2 = fopen('C:\Users\simon\Documents\data_olivier\adj_proj.txt','r');
% while(~feof(file2))
%     l = fgets(file2)
%     mat2 = sscanf(l,'%i')
%     extremites = [mean(polygones{mat2(1)+1},2) mean(polygones{mat2(2)+1},2)];
%             plot3(extremites(1,:),extremites(2,:),extremites(3,:),'-bs','LineWidth',5);
% end

