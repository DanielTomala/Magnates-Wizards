# Magnates & Wizards

Student project for second semester of Computer Science studies. Project was created by group of four students (Zuzanna Damszel, Ireneusz Okniński, Paweł Rogóż, Daniel Tomala), but I was one of main contributors. Game was created in C++ with usage of SFML library
It's turn-based game, where two players compete against each other to kill all opponent's heroes. Every player has to choose four heroes out of eight available. Following, player has to choose a style for each hero, there are three of them: long attack range, large damage and balanced. Game ends, when one of the players kills all opponent's heroes.

There are eight heroes classes, which differ from each other:
  - **Knight** - Knight is default hero class, he can only attack adjacent fields. He doesn't have any special abilities.

  - **Archer** - Archer has long attack range, but he gives little damage and has litte health. He doesn't have any special abilities.

  - **Mage** - Mage gives large damage to chosen opponent's hero and smaller damage to all other opponent's heroes.

  - **IceDruid** - IceDruid gives damage to opponent's hero and freezes him for the next round. Frozen hero neither can move nor attack.

  - **Medic** - Medic gives little damage, but he has ability to heal other ally.

  - **Ninja** - Ninja has large moving range and has ability to give three attacks in one turn.

  - **Catapult** - Catapult can't move, it gives huge damage at area of one field.

  - **Trebuchet** - Trebuchet also can't move, it gives small damage during next two turn at area of nine adjacent fields.


 ![magantes_wizards](https://user-images.githubusercontent.com/73648335/182908374-b4913609-cc75-4404-9a08-009134700cd0.png)
