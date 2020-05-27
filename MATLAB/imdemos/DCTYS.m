function Y = DCTYS(X,N)
%Y = DCTYS(X)，X为输入图像，压缩量N，Y为X经过DCT压缩之后的返回图像
 if  ~isa(X,'double')  
       I1=double(X)/255;
end
        T=dctmtx(8);
        B=blkproc(I1,[8 8],'P1*x*P2',T,T');
mask=zeros(8);
mask(1:N,1:N)=1;
B2=blkproc(B,[8 8],'P1.*x',mask);
Y=blkproc(B2,[8 8],'P1*x*P2',T',T);  