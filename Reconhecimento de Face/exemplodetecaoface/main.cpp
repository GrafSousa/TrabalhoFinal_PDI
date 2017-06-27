#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;
int main( )
{
    int TAM = 80;
    char str[TAM];
    cout << "Entre com o nome da imagem: " << endl;
    cin.getline(str, TAM);

    Mat imagem_entrada;
    Mat imagem_saida;
    Mat imagem;

    imagem_entrada = imread("figura1.png", CV_LOAD_IMAGE_COLOR );
    imagem = imread("facesC.jpg", CV_LOAD_IMAGE_COLOR);
    //namedWindow( "Figura Original",0 );
    //imshow( "Figura Original", imagem_entrada );

    char nome_arquivo[200]; // Usada para salvar as faces recortadas

    Size tamanho(300,300); // Usada na função resize

    resize(imagem_entrada, imagem_saida, tamanho);
    //imshow( "Figura Figura saida", imagem_saida );

    // carrega o arquivo de treinamento
    CascadeClassifier face_cascade;
    face_cascade.load( "haarcascade_frontalface_alt2.xml" );

    // procura faces
    std::vector<Rect> faces;
    face_cascade.detectMultiScale( imagem, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );

    //desenha circulos
    for( int i = 0; i < faces.size(); i++ ){
        cout<<"X: "<<faces[i].x <<  "  Y: "<<faces[i].y <<endl;
        //Point center(faces[i].x + faces[i].width* 0.5, faces[i].y + faces[i].height * 0.5);
        Point topo(faces[i].x, faces[i].y);
        Point base(faces[i].x + faces[i].width , faces[i].y + faces[i].height);

        rectangle(imagem, topo,  base, Scalar(0, 51, 255), 2, 8, 0);

        Mat ROI(imagem, Rect( faces[i].x, faces[i].y, faces[i].width, faces[i].height));
        imwrite()
        imshow("Teste ROI", ROI);
    }

    //namedWindow("Faces Encontradas",0);
    //imshow("Faces Encontradas", imagem);
    waitKey(0);
    return 0;
}
