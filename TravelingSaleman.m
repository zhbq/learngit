clc

tic
d = 10000;
A = table2array(tsp);
fig = figure;
z = 1;
filename = 'testAnimated.gif';
for i = 1:100
    dt = 0;
    for j = 1:999
        t = randperm(1000);
        x = A(t,1);
        y = A(t,2);
        alpha = sqrt((x(j+1)-x(j))^2+(y(j+1)-y(j))^2);
        dt = dt + alpha;     
    end
    x(1001) = x(1);
    y(1001) = y(1);
    dt = dt + sqrt((x(1001)-x(1000))^2+(y(1001)-y(1000))^2);
    if dt < d
        d = dt;
        plot(x,y);
        drawnow
        
        frame = getframe(fig); 
        im = frame2im(frame); 
        [imind,cm] = rgb2ind(im,256);
        if z == 1
        imwrite(imind,cm,filename,'gif','LoopCount',Inf);   
        else
        imwrite(imind,cm,filename,'gif','WriteMode','append');
        end
        z = z + 1;
    end
end
toc




