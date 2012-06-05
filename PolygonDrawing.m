close all
file = fopen('maison.txt','r')
figure;
hold on
polygones={}
i=1;
while(~feof(file))
    l = fgets(file)
    mat = sscanf(l,'%f')
    mat = reshape(mat,3,[])
    X = mat(1,:)
    Y = mat(2,:)
    Z = mat(3,:)
    polygones{i}=mat;
    i=i+1;
    %patch(X,Y,Z,i,'FaceAlpha',0.5)
     patch(X,Y,Z,[0.5 0.5 0.5],'FaceAlpha',0.5)
end

file2 = fopen('adja.txt','r')
mat2 = fscanf(file2,'%i')
mat2 = reshape(mat2,size(polygones,2),size(polygones,2));
for i=1:size(polygones,2)
    for j=1:(i-1)
        if(mat2(i,j)==1)
            extremites = [mean(polygones{i},2) mean(polygones{j},2)];
            plot3(extremites(1,:),extremites(2,:),extremites(3,:),'-bs');
        end
    end
end
hold off