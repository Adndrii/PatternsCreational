#include <iostream>
#include <string>
#define CREATIONAL

using namespace std;



#ifdef CREATIONAL
#include "CREATIONAL/AbstractFactory.h"
#include "CREATIONAL/Builder.h"
#include "CREATIONAL/FactoryMethod.h"
#include "CREATIONAL/Prototype.h"
#include "CREATIONAL/Singleton.h"
#endif // CREATIONAL



int main()
{
#ifdef CREATIONAL
    // Singleton
    GameManager& gameManager = GameManager::getInstance();
    gameManager.showGameStatus();

    // Factory Method
    HeroFactory* antiMageFactory = new AntiMageFactory();
    Hero* antiMage = antiMageFactory->createHero();
    antiMage->showHero();
    delete antiMage;
    delete antiMageFactory;

    HeroFactory* crystalMaidenFactory = new CrystalMaidenFactory();
    Hero* crystalMaiden = crystalMaidenFactory->createHero();
    crystalMaiden->showHero();
    delete crystalMaiden;
    delete crystalMaidenFactory;

    // Builder
    Director director;
    ItemBuilder* builder = new ConcreteItemBuilder();
    director.setBuilder(builder);
    director.construct();
    Item* item = builder->getResult();
    item->show();
    delete item;
    delete builder;

    // Prototype
    HeroPrototype* antiMagePrototype = new AntiMagePrototype("Anti-Mage");
    HeroPrototype* cloneAntiMage = antiMagePrototype->clone();
    cloneAntiMage->use();
    delete antiMagePrototype;
    delete cloneAntiMage;

    HeroPrototype* crystalMaidenPrototype = new CrystalMaidenPrototype("Crystal Maiden");
    HeroPrototype* cloneCrystalMaiden = crystalMaidenPrototype->clone();
    cloneCrystalMaiden->use();
    delete crystalMaidenPrototype;
    delete cloneCrystalMaiden;

    // Abstract Factory
    AbstractFactory* radiantFactory = new RadiantFactory();
    AbstractHero* radiantHero = radiantFactory->createHero();
    radiantHero->use();
    delete radiantHero;
    delete radiantFactory;

    AbstractFactory* direFactory = new DireFactory();
    AbstractHero* direHero = direFactory->createHero();
    direHero->use();
    delete direHero;
    delete direFactory;


#endif 

    return 0;
}