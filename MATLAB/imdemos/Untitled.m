 I=imread('testpat1.png');
                 J=imread('circles.png');
                 K=imadd(I,J);
                 subplot(131);imshow(I);
                 subplot(132);imshow(J);
                 subplot(133);imshow(K);
