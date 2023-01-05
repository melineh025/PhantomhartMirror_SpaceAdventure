
# Phantomheart
 
  Authors: [Justin Sanders](https://github.com/RiotRaider), [Aaron Tam](https://github.com/Homestuck126), and [Melineh Mansour Cheharmohali](https://github.com/melineh025)

## Project Description
  * Theme:
    * A Sci-fi/Fantasy Treasure Hunting Adventure
  * Motivation:
    * Video games are growing in popularity and importance within society, as computing students with an interest in the area we were interested in developing our own game for this project. This will challenge us to improve our own skills while working as a team and give us a greater appreciation for the amount of effort that is invested in the development of the games we enjoy. 
  * Language:
    * C++ 
  * Tools:
    * [Googletest](https://github.com/google/googletest) - Google's testing suite for checking methods and outputs
    * Valgrind
    * CMake
  * Input/Output:
    * Input: Accept user commands at regular intervals.
    * Output: Interactive adventure game with some randomized encounters.
  * Design Patterns:
    * Composite:
       * This pattern will allow us to plan and implement the character objects for both the user and all non-player characters. Both player and non-player characters will possess a name, inventory, level, and base attributes. These will all behave the same regardless of the type of character. Stats will be determined by a Character Generator and scaling factors will be applied with each level. All of these characters will need to be able to access their inventory the same and will also need to be engage with eachother in combat the same. However the Player character would have additional objects and methods to allow for changing equipment and healing. These would all be handled by additional methods defined under the Player class object while non-player characters would not need these additional features.
         * A Character object will all contain an inventory object composed of multiple item objects
         * A Map object will inherit and also be composed of individual Tile Objects that store information about themselves as well as their adjacencies.
    * Abstract Factory: 
      * We will be using abstract factory, for example, to create a variety of enemies that will inherit from one enemy blueprint. Abstract factory will allow the game to have a random nature to it, without needing to know the specific  attributes of mob enemies. Additionally, it will provide intersection and union of functionaility because each the factory method will allow new characters to be created quickly. These characters or enemies will require creation during run-time based on random attributes and the factory design method can efficently solve this issue. 
   * Factory:
      * The Factory Pattern will be used similarly to the Abstract Factory for Gear creation, but will be applied to control the generation of the player character and enemies. It will regulate stats being assigned to characters as well as controlling how gear is assigned. With Players being limited to a selection of starting equipment, and enemies being randomly created based on several parameters that can be dictated for testing or randomized during the run to provide more varied experiences for the player.   
## Class Diagram
 
### Composite Pattern:
![Composite](https://user-images.githubusercontent.com/60371257/120250229-377ca100-c232-11eb-8042-0030565aa746.png)




#### Character/Inventory/Quests

 There will be a base class "Character" that is contains an Inventory object. This Inventory object will serve as a directory and management object containing complex Weapon and Armor objects as well as counters for how many "simple" items it has. From the Character, a more complex Player object will be derived, while all other characters will utilize the original Character Class. External to the Character, there will be a QuestLog object that is composed of and manages multiple Quest objects, each of which containing the relevant information for initiating, progressing, and completing in game objectives.
#### Map

This is the Map class UML diagram, the purpose of this is to create a relationship where Map contains Tile. We are going to generate the entire map in the main, and everything will be made in a generate function there. The map and Tile constructors will be called at the start of the program, and we would generate each Tile and set their adjacencies, then we would insert them into map so that we can delete and interact with the Tile objects easily. We will generate each Map tile with four pointers to navigate our character through the Map. The Map will also track the current Tile the Character is on, returning the current Tile when the Player object asks for it. This map is a composite structure because it allows the Map to be consistent of not only Tile objects but also Map objects. This will allow for maps with sub maps. 


### Abstract Factory Pattern:


### Item Genereation for different Classes
![AbstractWeaponsTemp](https://user-images.githubusercontent.com/81594784/120052194-ede54980-bfd8-11eb-9811-bd67fb20c959.jpg)

 
 Every enemy created belongs to a certain Race, and within each race there are different classes that can spawn. These classes all require different sets of weapons and armor. The getEnemy() method will determine what specific enemy it needs to create, but the individual gear factories will determine the correct weapon and armor needed for each one.. This diagram shows the interface that GearFactory provides, such as createWeapon(), allows different factories to be created, each with access to their own sets of weapons and armor to allow for a unified theme between races. For example, and Elf class will get a weapon from one set of Concrete weapons and Armor such as a Bow or a Spear, and LightArmor. While an Orc will recieve an Axe and HeavyArmor. This allows easy expansion of variety using the same existing weapons and armor by building additional gear factories that will return combinations of Weapons and Armor drawn from different subsets of the Concrete Weapon and Armor Objects. 

 

### Factory Pattern:
![CharacterFactory](https://user-images.githubusercontent.com/81594784/120246443-195c7400-c225-11eb-97b6-1ce50cc7adb5.jpg)

  

Player and Non-Player Characters will be created using the basics of the Factory Pattern. The Player generation method will use user input to determine what starting equipment and corresponding attributes will be assigned to the player's character. Enemys will be generated by a different function within the factory that will accept externally generated integers to determine what race and class of enemy to generate, utilize the GearFactory objects to generate appropriate equipment for the new character object as well as determine the appropriate attributes scaled to the player character's level.

### No pattern

![Untitled Diagram](https://user-images.githubusercontent.com/60371257/119062742-5bb3c480-b98c-11eb-8e15-206452975ee9.png)

#### Quest
This is the Quest class UML digram, the purpose of this is to create a relationship where Questlog contains Quests. We are once again going to gnerate the entire Questlog in the main, and everything will be made in a generate function there. Every Quest will then be generated and inserted into Questlog to allow for easy deletion and interaction. Each Quest will be generated with 2 Tile pointers so that Questlog can communicate with Map and determine when quests are active and when they will start and end. The Questlog will be the main thing to tell the player what to do to win the game. 

#### Menu

![MENU](https://user-images.githubusercontent.com/74107543/120247836-c0430f00-c229-11eb-9bac-fdf81d3a0c5c.png)

The Menu UML is defined as a parent class with CombatMenu, MoveMenu, and CombatMenu inherting from it. Each subclass is responsible for displaying the correct menu to the user and then handling the input it recieves. It provides the basic infrastructure that the client code will use to generate the game components and display to the player. Some menus can be composed of other menus, such as the core menu contains a movmement menu within it. In future expansions of the game, adding a new menu will be easy due to do predefined functionalities shown in this diagram.  


 
 ## Screenshots
 #### Main Menu
 ![Main Menu](https://user-images.githubusercontent.com/81594784/120244714-d9df5900-c21f-11eb-80ac-5a621578b59d.jpg)
 #### Character Creation
 ![Character Creation](https://user-images.githubusercontent.com/81594784/120244719-dfd53a00-c21f-11eb-8965-5124d784f292.jpg)
 #### World Menu
 ![Core Menu](https://user-images.githubusercontent.com/81594784/120244729-e5328480-c21f-11eb-8ff0-fe2a820c7f58.jpg)
 #### Movement
 ![Move](https://user-images.githubusercontent.com/81594784/120244742-ed8abf80-c21f-11eb-932a-e1507079120e.jpg)
 #### Quest Objective
 ![Check Objective](https://user-images.githubusercontent.com/81594784/120244872-4c503900-c220-11eb-980d-7b52fc99408f.jpg)
 #### Inventory
 ![Inventory Screen](https://user-images.githubusercontent.com/81594784/120244795-085d3400-c220-11eb-83b0-8b4c8fd739a9.jpg)
 #### Combat
 ![Combat](https://user-images.githubusercontent.com/81594784/120244759-f8ddeb00-c21f-11eb-9756-f850e0856f6e.jpg)
 #### Looting (Post-Combat)
 ![Loot](https://user-images.githubusercontent.com/81594784/120244774-fed3cc00-c21f-11eb-8051-8757e12e0a52.jpg)
 ## Installation/Usage
 This game must be used on a CMake compatible environment (Linux or an IDE with CMake installed such as Visual Studio 2019)
 
 Command-Line:
  * Clone repository into your target directory
   * Git clone --recursive <URL> 
  * Run "cmake ." and "make"
  * Run the game with "./Phantomheart"
 
 Visual Studio:
 * Open Visual Studio
 * Clone github repository
 * Cmake will run automatically if installed
 * From the Dropdown menu by the Green triangle and select "Phantomheart"
 * Hit the green triangle once executable is selected
  
 
 ## Testing
 All independent componenents were tested using the google test submodule.
  * Inventory
  * Character and Player
  * Quest and Quest Log
  * Map and MapTiles
  * Gear Factories
  * Charactor Factory
  * Weapons and Armor

Integration Components contained several levels of randomness. These were tested by rigorous play testing. Any bugs encountered were logged and consolidated to be corrected.

Finally the Executable was run using Valgrind throughout development to identify memory leaks and seal them before progressing.
