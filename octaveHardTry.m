LENA_COL = imread('test_img/lena_color.png');
red = LENA_COL(:,:,1);
green = LENA_COL(:,:,2);
blue = LENA_COL(:,:,3);


W = cat(1,(red+green+blue)/3);
imwrite(W, 'aaacoto.png');


red = 0.299*red;
green  = 0.587*green;
blue = 0.114*blue;
W = cat(1, red+green+blue);

imwrite(W, 'aaatoto.png');