close all
file = fopen('hlm.txt','r')
figure;
hold on
polygones={}
i=1;
marche=3;
file3=fopen('liste_meilleur.txt','r');
mat3 = fscanf(file3,'%i');
mat3 = reshape(mat3,1,[])
colormap(jet)
while(~feof(file))
    l = fgets(file);
    mat = sscanf(l,'%f');
    mat = reshape(mat,3,[]);
    X = mat(1,:);
    Y = mat(2,:);
    Z = mat(3,:);
    polygones{i}=mat;
    size(X)
    
    %patch(X,Y,Z,randi(200),'FaceAlpha',0.5)
    patch(X,Y,Z,randi(200),'FaceAlpha',1)
%     if(size(find(mat3==i))>0)
%         j = find(mat3==i);
%         j=j(1);
%         patch(X,Y,Z,[1 0 0],'FaceAlpha',1)
%     else
%         patch(X,Y,Z,[0.5 0.5 0.5],'FaceAlpha',0.01)
%     end
    i=i+1;
end
size(polygones)
file2 = fopen('adja.txt','r');
mat2 = fscanf(file2,'%i');
mat2 = reshape(mat2,size(polygones,2),size(polygones,2));
for i=1:size(polygones,2)%[mat3(2*marche) mat3(2*marche+1)]
    for j=1:(i-1)%[mat3(2*marche) mat3(2*marche+1)]
        if(mat2(i,j)==1)
            extremites = [mean(polygones{i},2) mean(polygones{j},2)];
            plot3(extremites(1,:),extremites(2,:),extremites(3,:),'-bs');
        end
    end
end

%file4 = fopen('liste_meilleur.txt','r')
file4 = fopen('tous.txt','r')
i=0;
while(~feof(file4))
    l = fgets(file4);
    mat = sscanf(l,'%i');
figure;
hold on
    for j=mat'
        patch(polygones{j}(1,:),polygones{j}(2,:),polygones{j}(3,:),ceil(i/2),'FaceAlpha',1)
    end
    
 for j=1:size(polygones,2)
      patch(polygones{j}(1,:),polygones{j}(2,:),polygones{j}(3,:),[0.5 0.5 0.5],'FaceAlpha',0.5)
 end
hold off
    i=i+1;
end