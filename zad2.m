

function pauza
    % dokoncz rysowanie wykresow
    drawnow;
    % poczekaj na reakcje uzytkownika
    input('Nacisnij Enter: ', 's');
    % zamknij okna z wykresami
    close all;
end


IMG = imread('test_img/obrazek.png');

OBR = imfilter (IMG, [0 1 0; 0 -1 0; 0 0 0]);

B = OBR > 200;
AVE = imsmooth(IMG, "average");

WYNIK = !B .* AVE + B .* IMG;
imshow(IMG - WYNIK + 127);
pauza;
imwrite(WYNIK, 'wynik05.png');