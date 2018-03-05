#ifndef MONSTER_H
#define MONSTER_H

#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Encounterable.hpp"
//#include "../screen/EncounterScreen.hpp"
#include "../utils/AnimatedSprite.hpp"

enum MonsterSpecies {
    dinosaur
};

class Monster: public Encounterable, public AnimatedSprite {
public:
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Constructor method.
     * @param MonsterSpecies type
     */
    Monster(MonsterSpecies s, sf::Window& window);
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Default constructor method.
     * @param Original Monster
     */
    Monster(const Monster& orig);
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Default destructor method. Deletes:
     *   -FightScreen
     *   -Texture (temporary)
     */
    virtual ~Monster();
    
    
    /* Implemented Abstract Methods */
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Tells whether the Encounterable can be passed without
     * interacting. For Monster, this will always be false.
     * @return Whether Player must interact to pass (false)
     */
    bool isSkippable() const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Gets name string associated with a subclass. This value 
     * will be the same for all instances of a given subclass.
     * For Monster, this will always be "Monster"
     * @return String name for given subclass ("Monster")
     */
    std::string getTypeName() const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Gets RoomType enumerator value associated with a subclass.
     * This value will be the same for all instances of a given
     * subclass. For Monster, this will always be monster
     * @return RoomType value for given subclass (monster)
     */
    RoomType getType() const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Interact with the Monster - WIP
     */
    void encounter(Player& player);
    
    virtual void drawExtras(sf::RenderTarget& target, sf::RenderStates states) const;
    
    
    /* Original Methods */
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Gets the Monster's name, so you can introduce yourself
     * properly. Mostly an aesthetic feature, but they're people
     * too.
     * @return Name of the Monster
     */
    std::string getName() const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Get maximum possible health for the Monster.
     * @return Maximum health
     */
    int getMaxHealth() const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Get the Monster's current health. This is the variable
     * that the fight will change.
     * @return Monster's current HP
     */
    int getHealth() const;
    
    /* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
     * 
     * Get a MonsterSpecies enumerator value representing the
     * species (type) of Monster.
     * @return The Monster's type as an enum
     */
    MonsterSpecies getSpecies() const;
    
    virtual void run(sf::Event event) {};
    void changeHealth(int n);
    
    HealthBar healthbar;
    
private:
    /* The Monster's name */
    std::string name;
    
    /* The maximum health possible */
    unsigned int maxHealth;
    
    /* The current health*/
    unsigned int health;
    
    /* Pointer to the Monster texture */
    sf::Texture* monster_texture;
    
    /* Enum to hold what type of Monster */
    MonsterSpecies species;
    
    /*  */
    std::string getSpeciesTexture();
};

#endif /* MONSTER_H */
