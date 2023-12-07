#include "Location.h"
#include "Item.h"
#include "Player.h"

using namespace std;

//Location class
//Sets a Locations name and description
//Returns a Locations name and description
//Allows for items to be added to a location
//Allows for two locations to be connected (next to each other)
//Allows for an npc to be added to a location

//Constructor
Location::Location(string newName, string newDescription) : name(newName), description(newDescription) {
    // Initialize other members as needed...
}

//Constructor 2
Location::Location(string newName, string newDescription, Location *loc) : name(newName), description(newDescription), hidden(loc){
    // Initialize other members as needed...
}


// Returns a string of the Locations name
string Location::getName()
{
	return name;
}


// Returns a string of the Locations description
string Location::getDescription()
{
	return description;
}

// Add a connected location to this location
void Location::addConnectedLocation(Location* location) {
    connectedLocations.push_back(location);
}

// Get the list of connected locations
list<Location*> Location::getConnectedLocations() const {
    return connectedLocations;
}

// Add an item to the location
void Location::addItem(Item* item) {
    items.push_back(item);
}

// Get an item from the location
list<Item*> Location::getItems() const {
    return items;
}

// Remove an item from a location
bool Location::removeItem(Item* item) {
    items.remove(item);
    return true; // Return true if the item was found and removed, you can add error handling if needed.
}

// Check if the specified item exists in the location's item list.
bool Location::hasItem(const Item* item) const {
    return std::find(items.begin(), items.end(), item) != items.end();
}

void Location::printImage()

{

    string castle =
        R"(                                                
                                                  |*~=-.,
                                                  |_,-'`!_
                                                  |
                                                  |
                                                 /^\
                   !_                           /   \
                   |*`~-.,                     /,    \
                   |.-~^`                     /#"     \
                   |                        _/##_   _  \_
              _   _|  _   _   _            [ ]_[ ]_[ ]_[ ]
             [ ]_[ ]_[ ]_[ ]_[ ]            |_=_-=_ - =_|
           !_ |_=_ =-_-_  = =_|           !_ |=_= -    |
           |*`--,_- _        |            |*`~-.,= []  |
           |.-'|=     []     |   !_       |_.-"`_-     |
           |   |_=- -        |   |*`~-.,  |  |=_-      |
          /^\  |=_= -        |   |_,-~`  /^\ |_ - =[]  |
      _  /   \_|_=- _   _   _|  _|  _   /   \|=_-      |
     [ ]/,    \[ ]_[ ]_[ ]_[ ]_[ ]_[ ]_/,    \[ ]=-    |
      |/#"     \_=-___=__=__- =-_ -=_ /#"     \| _ []  |
     _/##_   _  \_-_ =  _____       _/##_   _  \_ -    |\
    [ ]_[ ]_[ ]_[ ]=_0~{_ _ _}~0   [ ]_[ ]_[ ]_[ ]=-   | \
    |_=__-_=-_  =_|-=_ |  ,  |     |_=-___-_ =-__|_    |  \
     | _- =-     |-_   | ((* |      |= _=       | -    |___\
     |= -_=      |=  _ |  `  |      |_-=_       |=_    |/+\|
     | =_  -     |_ = _ `-.-`       | =_ = =    |=_-   ||+||
     |-_=- _     |=_   =            |=_= -_     |  =   ||+||
     |=_- /+\    | -=               |_=- /+\    |=_    |^^^|
     |=_ |+|+|   |= -  -_,--,_      |_= |+|+|   |  -_  |=  |
     |  -|+|+|   |-_=  / |  | \     |=_ |+|+|   |-=_   |_-/
     |=_=|+|+|   | =_= | |  | |     |_- |+|+|   |_ =   |=/
     | _ ^^^^^   |= -  | |  <&>     |=_=^^^^^   |_=-   |/
     |=_ =       | =_-_| |  | |     |   =_      | -_   |
     |_=-_       |=_=  | |  | |     |=_=        |=-    |
^^^^^^^^^^`^`^^`^`^`^^^""""""""^`^^``^^`^^`^^`^`^``^`^``^``^^|___/              |___/       
	)";



    string hare =
        R"(

                     .".
                         /  |                                                                                                                           
                        /  /
                       / ,"
           .-------.--- /
          "._ __.-/  O   \  
             "   (    Y  )
                  )     /
                 /     (
                /       Y
            .-"         |
           /  _     \    \ 
          /    `. ". ) /' )                                  
         Y       )( / /(,/
        ,|      /     )
       ( |     /     /                                                                              
        " \_  (__   (__      
            "-._,)--._,)



)";

    string fairy =
        R"(

                             
                                                  
              (\  _               (\  _           
  (\  _  (\  _  ( \ c  (\  _        ( \ c           
( \ c  ( \ c   (/(\/ ( \ c  (\  _  (/(\/          
 (/(\/  (/(\/    /|   (/(\/ ( \ c    /|           
   /|     /|    / |     /|   (/(\/  / |           
  / |    / |   /__|    / |     /|  /__|           
 /__|   /__|     "    /__|    / |    "            
   "      "      (\  _  "    /__|    


)";

    string dungeon =
        R"(

                            
                                                  
    _________________________________________________________
 /|     -_-                                             _-  |\
/ |_-_- _                                         -_- _-   -| \   
  |                            _-  _--                      | 
  |                            ,                            |
  |      .-'````````'.        '(`        .-'```````'-.      |
  |    .` |           `.      `)'      .` |           `.    |          
  |   /   |   ()        \      U      /   |    ()       \   |
  |  |    |    ;         | o   T   o |    |    ;         |  |
  |  |    |     ;        |  .  |  .  |    |    ;         |  |
  |  |    |     ;        |   . | .   |    |    ;         |  |
  |  |    |     ;        |    .|.    |    |    ;         |  |
  |  |    |____;_________|     |     |    |____;_________|  |  
  |  |   /  __ ;   -     |     !     |   /     `'() _ -  |  |
  |  |  / __  ()        -|        -  |  /  __--      -   |  |
  |  | /        __-- _   |   _- _ -  | /        __--_    |  |
  |__|/__________________|___________|/__________________|__|
 /                                             _ -        lc \


)";


   string bridge =
        R"(

                            
                                                  
  ______________________________________________________
   [[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]-[[]]
   .-.`| `-/-.__/.-'\_.-._,'/`-._'\_.-._`-'_/-._.'|/.-'\-
   \_.-`./`-._'\__.-`-.__.-`--._/--.`-._\`-._\__.-)`-'._/
   `._-'.\_.---._-.\_`-..`\_.---._`-.__.-`'._.--./`-'._,'
   __/`.-/       `.'_`./`.'       '.\__.-`.'    (_.-\_,-.
   `._-/'          |._.-|           |.'`.|       `(_.`-._
   .-',`)          | /`.|           |`-/`|         ;.-'_/
   `\,-/           |\.-'|           |\-'`|          ;\_,-
    -./`._        [[[[[[[[         [[[[[[[[         .',-'
    `.`--.~~-^_~-/.`-._`-.\^~-_~-^/`-.'-,.'\^~-~_^"'`-.'_


)";



   string kelpie =
       R"(

                            

   ,^,.,,.
   ,;7~((\))`;;,,
   ,(@') ;)`))\;;',
    )  . ),((  ))\;,
   /;`,,/7),)) )) )\,,      ,,,... ,
  (& )`   (,((,((;( ))\,_,,;'`    `\\,
   `"    ` ), ))),/( (            `)\,
          '1/';/;  `               ))),
           (, (     /         )    ((/,
          / \                /     ((('
         ( 6--\%  ,>     ,,,(     /'))\'
          \,\,/ ,/`----~`\   \    >,))))'
            \/ /          `--7>' /((((('
            (,9             // /'('((\\\,
             \ \,,         (/,/   '\`\\'\
              `\_)1        (_)Kk    `\`\\`\
                `\|         \Z          `\



)";


   string chest =
       R"(

                            

          
         
                    ____...------------...____
               _.-"` /o/__ ____ __ __  __ \o\_`"-._
             .'     / /                    \ \     '.
             |=====/o/======================\o\=====|
             |____/_/________..____..________\_\____|
             /   _/ \_     <_o#\__/#o_>     _/ \_   \
             \_________\####/_________/
              |===\!/========================\!/===|
              |   |=|          .---.         |=|   |
              |===|o|=========/     \========|o|===|
              |   | |         \     /        | |   |
              |===|o|======{'-.)   (.-'}=====|o|===|
              | __/ \__     '-.\___/.-'    __/ \__ |
              |==== .'.'^'.'.====|
              |  _\o/   __  {.' __  '.} _   _\o/  _|
              `""""-""""""""""""""""""""""""""-""""`


)";

   string swamp=
       R"(

                            

          
                
                                   # #### ####
                                ### \/#|### |/####
                               ##\/#/ \||/##/_/##/_#
                             ###  \/###|/ \/ # ###
                           ##_\_#\_\## | #/###_/_####
                          ## #### # \ #| /  #### ##/##
                           __#_--###`  |{,###---###-~
                                     \ }{
                                      }}{
                                      }}{
                ,,,                   }}{  ,,,
       {{{}}    ,,,             {{{}} }}{   ,,,
    ,,, ~Y~    {{{}},,,      ,,, ~Y~   }}{ {{{}},,, 
   {{}}} |/,,,  ~Y~{{}}}    {{}}} |/,,,  ~Y~{{}}}
    ~Y~ \|{{}}}/\|/ ~Y~  ,,, ~Y~ \|{{}}}/\|/ ~Y~  ,,,
    \|/ \|/~Y~  \|,,,|/ {{}}}\|/ \|/~Y~  \|,,,|/ {{}}}
    \|/ \|/\|/  \{{{}}/  ~Y~ \|/ \|/\|/  \{{{}}/  ~Y~
    \|/\\|/\|/ \\|~Y~//  \|/ \|/\\|/\|/ \\|~Y~//  \|/
    \|//\|/\|/,\\|/|/|// \|/ \|//\|/\|/,\\|/|/|// \|/
jgs^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

)";

   string hall=
       R"(

                            

                 _I_
               .~'_`~.
         /(  ,^ .~ ~. ^.  )\
         \ \/ .^ |   ^. \/ /
          Y  /   |     \  Y            ___.oOo.___ 
          | Y    |      Y |           |           |
          | |    |      | |           |           |
          | |   _|___   | |           |           |
          | |  /____/|  | |           |           |
          |.| |   __/|__|.|           |           |
          |.| |   __/|  |.|          _|___________|_
          |:| |   __//  |:|         '^^^^^^^^^^^^^^^`
          |:| |_____/   |:|
      ____|_|/          |_|_____________________________
      ____]H[           ]H[_____________________________
           /             \
          
                         

)";


   string outside=
       R"(

                            
       {{{}}    ,,,             {{{}}    ,,,
    ,,, ~Y~    {{{}},,,      ,,, ~Y~    {{{}},,,
   {{}}} |/,,,  ~Y~{{}}}    {{}}} |/,,,  ~Y~{{}}}
    ~Y~ \|{{}}}/\|/ ~Y~  ,,, ~Y~ \|{{}}}/\|/ ~Y~  ,,,
    \|/ \|/~Y~  \|,,,|/ {{}}}\|/ \|/~Y~  \|,,,|/ {{}}}
    \|/ \|/\|/  \{{{}}/  ~Y~ \|/ \|/\|/  \{{{}}/  ~Y~
    \|/\\|/\|/ \\|~Y~//  \|/ \|/\\|/\|/ \\|~Y~//  \|/
    \|//\|/\|/,\\|/|/|// \|/ \|//\|/\|/,\\|/|/|// \|/
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                         

)";

   string god=
       R"(

     
             .---.
            / ,-- \
           ( (^_^) )  
           (.-`-'(_)  
          -/ \ `.  \
          /   \_ ") \ 
          \ \     / /.
           `.\, ,'.'  
            /\_  /\   
           : ""T"" :  
          '|   H   |`
           |   H .:|   
           | . H !||
           | : H :!|
           | ! H !||
           | | H |||
           | | H |||  
           /_,'V.L|.\

)";

   string sword =
       R"(

     
                          .---.
                           ___
                          ( ((
                           ) ))
  .::.                    / /(
 'M .-;-.-.-.-.-.-.-.-.-/| ((::::::::::::::::::::::::::::::::::::::::::::::.._
(J ( ( ( ( ( ( ( ( ( ( ( |  ))   -====================================-      _.>
 `P `-;-`-`-`-`-`-`-`-`-\| ((::::::::::::::::::::::::::::::::::::::::::::::''
  `::'                    \ \(
                           ) ))
                          (_((

)";

   string water =
       R"(

     
                          _      _      _      _      _ 
)`'-.,_)`'-.,_)`'-.,_)`'-.,_)`'-.,_)`'-.,_)`'-.,_)`'-.,_)`'-.,_)`'-.,_)`'-.,_)`'-.,_)`'-.,_)`'-.,_)`'-.,_)`'-.,_
_     _     _     _     _     _     _     _
)`'-.,)`'-.,)`'-.,)`'-.,)`'-.,)`'-.,)`'-.,)`'-.,)`'-.,_)`'-.,_)`'-.,_)`'-.,_)`'-.,_)`'-.,_)`'-.,_)`'-.,_
_    _    _    _    _    _    _    _    _
)'-.,)'-.,)'-.,)'-.,)'-.,)'-.,)'-.,)'-.,)'-.,)`'-.,_)`'-.,_)`'-.,_)`'-.,_)`'-.,_)`'-.,_)`'-.,_)`'-.,_
 _       _      _       _      _      _
( `'-.,_( `'-.,( `'-.,_( `'-._( `'-.,( `'-.,)`'-.,_)`'-.,_)`'-.,_)`'-.,_)`'-.,_)`'-.,_)`'-.,_)`'-.,_

)";








    if (getName() == "Other side of the bridge")
    {
        cout << bridge << endl;
    }
    else if (getName() == "Other side of the lake")
    {
        cout << water << endl;
    }
    else if (getName() == "Lake")
    {
        cout << kelpie << endl;
    }
    else  if (getName() == "Swamp")
    {
        cout << swamp << endl;
    }
    else if (getName() == "Dungeon")
    {
        cout << dungeon << endl;
    }
    else  if (getName() == "Courtyard")
    {
        cout << castle << endl;
    }
    else if (getName() == "Armory")
    {
        cout << chest << endl;
    }
    else if (getName() == "Outside")
    {
        cout << outside << endl;
    }
    else if (getName() == "Nest")
    {
        cout << sword << endl;
    }
    else if (getName() == "Banquet Hall")
    {
        cout << fairy << endl;
    }
    else if (getName() == "Great Hall")
    {
        cout << hall << endl;
    }
    else if (getName() == "Meadow")
    {
        cout << hare << endl;
    }
    else if (getName() == "Bridge")
    {
        cout << bridge << endl;
    }
    else if (getName() == "The Goddess's Dwelling")
    {
        cout << god << endl;
    }
}