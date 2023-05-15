#include <QLabel>
#include <QProgressBar>
#include <QLCDNumber>
#include <QHBoxLayout>
#include <QMessageBox>

#include "vuepartie.h"
#include "vuecarte.h"
#include "combinaison.h"

VuePartie::VuePartie(QWidget *parent) : QWidget(parent), vuecartes(20,nullptr)
{
    controleur.distribuer();

    setWindowTitle("Set !");

    couche=new QVBoxLayout;
    setLayout(couche);

    layoutInformations= new QHBoxLayout;
    couche->addLayout(layoutInformations);

    pioche = new QLabel("Pioche");
    layoutInformations->addWidget(pioche);

    nbCartesPioche= new QProgressBar;
    nbCartesPioche->setRange(0,Set::Jeu::getJeu().getNbCartes());
    nbCartesPioche->setValue(controleur.getPioche().getNbCartes());
    nbCartesPioche->setFixedHeight(30);
    nbCartesPioche->setTextVisible(true); // pour ne pas afficher le % dans la barre
    layoutInformations->addWidget(nbCartesPioche);

    score = new QLabel("Score");
    layoutInformations->addWidget(score);

    scoreJoueur= new QLCDNumber;
    scoreJoueur->display(0); // score initial
    scoreJoueur->setFixedHeight(30);
    layoutInformations->addWidget(scoreJoueur);


    layoutCartes = new QGridLayout;
    couche->addLayout(layoutCartes);

    for(size_t i=0; i<20;++i) vuecartes[i]=new VueCarte;
    for(size_t i=0;i<20;++i){
        layoutCartes->addWidget(vuecartes[i],i/4,i%4);
        connect(vuecartes[i],SIGNAL(carteClicked(VueCarte*)),this,SLOT(carteClique(VueCarte*))); // connection au slot qui gère les clicks de carte
    }

    size_t i=0;
    for(auto &carte : controleur.getPlateau()){
        vuecartes[i]->setCarte(carte);
        i++;
    }




}

void VuePartie::carteClique(VueCarte* vc)
{
    if(!vc->cartePresente()){

        if(controleur.getPioche().getNbCartes()==0){// message d'erreur si la pioche est vide
            QMessageBox message(QMessageBox::Icon::Warning, "Attention", "La pioche est vide !");
            message.exec();
        }

        controleur.distribuer(); // sinon on ajoute une carte
        size_t i=0;
        for(auto &carte : controleur.getPlateau()){
            vuecartes[i]->setCarte(carte);
            i++;
        }
        nbCartesPioche->setValue(controleur.getPioche().getNbCartes());
    }
    else {
        if(vc->isChecked()){
            selectionCartes.insert(&vc->getCarte()); // si la carte est checkée, on l'insert dans l'ensemble des cartes sélectionnées
            if(selectionCartes.size()==3){
                // si le nb de carte sélectionnées est égal à 3, on vérifie si c'est un set
                vector<const Set::Carte*> c(selectionCartes.begin(),selectionCartes.end());
                Set::Combinaison combinaison(*c[0],*c[1],*c[2]);
                if(combinaison.estUnSET()){ // si c'est un set, on retire les cartes
                    for(auto carte : c)
                        controleur.getPlateau().retirer(*carte);
                    selectionCartes.clear();


                    if(controleur.getPlateau().getNbCartes()<12)
                        controleur.distribuer();

                    scoreValue++;
                    scoreJoueur->display(scoreValue);

                    for(size_t i=0; i<vuecartes.size();++i)
                        vuecartes[i]->setNoCarte();
                    size_t i =0;
                    for(auto & carte : controleur.getPlateau()){
                        vuecartes[i]->setCarte(carte);
                        ++i;
                    }
                    nbCartesPioche->setValue(controleur.getPioche().getNbCartes());
                }
                else {
                    QMessageBox message(QMessageBox::Icon::Warning, "Attention", "Ce n'est pas un set !");
                    message.exec();
                    // déselection des cartes
                    for(size_t i=0; i<vuecartes.size();++i)
                        vuecartes[i]->setChecked(false);
                    selectionCartes.clear();
                }
            }
        }
        else selectionCartes.erase(&vc->getCarte());
    }

    update();
}
