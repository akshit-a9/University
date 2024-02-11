clc;
clear all;

%IMPORTING IMAGE
ob=imread('D:\Coding Files\University\2022 ODD SEM\MATLAB\Baseball.jpg');
imshow(ob);


%SEGMENT IMAGE
%divde image into respective RGB in intenstites

r=ob(:,:,1);
b=ob(:,:,3);
g=ob(:,:,2);

figure(1)
subplot(2,2,1);
imshow(ob);
title('Original Image');
subplot(2,2,2);
imshow(r);
title('Red');
subplot(2,2,3);
imshow(g);
title('Green');
subplot(2,2,4);
imshow(b);
title('Blue');


%threshold blue plane
figure(2)
level=0.37;
bw2=im2bw(b,level);
subplot(2,2,1);
imshow(bw2);
title('Blue threshold');

%NOISE REMOVING
%Fill holes
fill=imfill(bw2,'holes');
subplot(2,2,2);
imshow(fill);
title('No holes');

%Remove blobs on the border of mage
blob=imclearborder(fill);
subplot(2,2,3);
imshow(blob);
title('Blobs removed');

%Removing blobs less than 7 pixel
spb=strel('disk',7);
open=imopen(fill,spb);
subplot(2,2,4);
imshow(open);
title('No small blob');

%OBJECT DIAMETER
dm=regionprops(open,'MajorAxisLength');

%RESULT
figure(3)
imshow(ob)
d=imdistline;






