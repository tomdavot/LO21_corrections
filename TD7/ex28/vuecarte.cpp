#include "vuecarte.h"
#include <QPainter>
#include <QString>
#include <QStaticText>
VueCarte::VueCarte(const Set::Carte& c, QWidget *parent) : QPushButton(parent),carte(&c)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(120,200);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(true);
}

VueCarte::VueCarte(QWidget *parent): QPushButton(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(120,200);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(false);
}

void VueCarte::paintEvent(QPaintEvent * /* event */)
{

    const QPoint pointsLosange[4] = {
        QPoint(50, 0),
        QPoint(100, 25),
        QPoint(50, 50),
        QPoint(0, 25),
    };
    const QPoint pointsVague[12] = {
        QPoint(0, 0),
        QPoint(20, 0),
        QPoint(20, 30),
        QPoint(40, 30),
        QPoint(40, 0),
        QPoint(100, 0),
        QPoint(100, 50),
        QPoint(80, 50),
        QPoint(80, 20),
        QPoint(60, 20),
        QPoint(60, 50),
        QPoint(0, 50),
    };

    QRect rect(0, 0, 100, 40);
    QPainter painter(this);

    // rectangle autour de la carte
    pen.setColor(QColor("gray"));
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(3);
    painter.setPen(pen);
    painter.drawRect(QRect(2, 2, width() - 2, height() - 2));

    if (carte==nullptr) { // si la vue de carte n'a pas de carte on affiche un message
        painter.drawText(QRect(15,50,100,60), Qt::AlignCenter, tr("cliquer \n pour \n ajouter \n une carte"));
        return;
    }

    // couleurs des formes
    switch (carte->getCouleur()) {
    case Set::Couleur::vert:
        pen.setColor(QColor("dark green")); brush.setColor(QColor("dark green")); break;
    case Set::Couleur::mauve:
        pen.setColor(QColor("magenta")); brush.setColor(QColor("magenta")); break;
    case Set::Couleur::rouge:
        pen.setColor(QColor("red")); brush.setColor(QColor("red")); break;
    }

    // remplissage
    switch (carte->getRemplissage()) {
    case Set::Remplissage::vide: brush.setStyle(Qt::NoBrush); break;
    case Set::Remplissage::plein: brush.setStyle(Qt::SolidPattern); break;
    case Set::Remplissage::hachure: brush.setStyle(Qt::VerPattern); break;
    }

    pen.setWidth(2);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.setRenderHint(QPainter::Antialiasing, true);

    int coeff_translation;
    int debut_y;
    switch (carte->getNombre()){
    case Set::Nombre::un: debut_y=75; coeff_translation=100; break;
    case Set::Nombre::deux: debut_y=35; coeff_translation=90; break;
    case Set::Nombre::trois: debut_y=20; coeff_translation=60; break;
    }
    for (size_t i = 0; i < static_cast<size_t>(carte->getNombre()); i++) {
        painter.save();
        painter.translate(10, coeff_translation*i+debut_y);
        switch (carte->getForme()) {
        case Set::Forme::vague:
            painter.drawPolygon(pointsVague, 12);
            break;
        case Set::Forme::losange:
            painter.drawPolygon(pointsLosange, 4);
            break;
        case Set::Forme::ovale:
            painter.drawEllipse(rect);
            break;
        }
        painter.restore();
    }

    if (isChecked()) { // si la carte est sélectionnée, on ajoute une croix noire
        pen.setColor(QColor("black"));
        painter.setPen(pen);
        painter.drawLine(QPoint(0,0), QPoint(width(),height()));
        painter.drawLine(QPoint(width(),0), QPoint(0,height()));
    }

}
