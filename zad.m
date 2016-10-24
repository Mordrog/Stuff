


IMG = imread('test_img/jetplane.png');

OBR = imfilter (IMG, [0 1 0; 0 -1 0; 0 0 0]);

B = OBR > 25;

CZ = cat (3, ones(512,512, "uint8")*255,zeros(512,512,"uint8"),zeros(512,512,"uint8"));

WYNIK = !B .* IMG + B .* CZ;

imwrite(WYNIK, 'wynik04.png');