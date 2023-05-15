#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

int question1(int argc, char *argv[])
{
    // Question 1
    QApplication app(argc, argv);
    QWidget fenetre;
    fenetre.setFixedSize(250, 120);
    fenetre.setWindowTitle("Joueur");

    QLineEdit* nom= new QLineEdit(&fenetre);
    nom->setFixedWidth(180);
    nom->move(60,10);

    QLabel* noml= new QLabel("Nom",&fenetre);
    noml->move(10,10);

    QPushButton* ok = new QPushButton("ok", &fenetre);
    ok->setFixedWidth(230);
    ok->move(10,60);

    fenetre.show();
    return app.exec();
}

int question2(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QWidget fenetre;
    fenetre.setFixedSize(250, 120);
    fenetre.setWindowTitle("Joueur");

    QLineEdit* boutton_nom= new QLineEdit(&fenetre);
    boutton_nom->setFixedWidth(180);

    QLabel* label_nom= new QLabel("Nom",&fenetre);
    label_nom->move(10,10);

    QPushButton* boutton_ok = new QPushButton("ok", &fenetre);
    boutton_ok->setFixedWidth(230);

    QHBoxLayout* layout_nom=new QHBoxLayout;
    layout_nom->addWidget(label_nom);
    layout_nom->addWidget(boutton_nom);

    QVBoxLayout* layout_couche= new QVBoxLayout;
    layout_couche->addLayout(layout_nom);
    layout_couche->addWidget(boutton_ok);
    fenetre.setLayout(layout_couche);

    fenetre.show();
    return app.exec();
}

int main(int argc, char *argv[])
{
    return question2(argc,argv);
}
