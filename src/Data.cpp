/****************************************************************************
 ** Hyne Final Fantasy VIII Save Editor
 ** Copyright (C) 2009-2013 Arzel Jérôme <myst6re@gmail.com>
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/
/****************************************************************************
 ** Part of this code was written by Qhimm in its Griever program.
 ** Source code available at http://qhimm.com/
 ****************************************************************************/

#include "Data.h"

Abilities Data::_abilities;
Magics Data::_magic;
Items Data::_items;
Locations Data::_locations;
Cities Data::_cities;
Weapons Data::_weapons;
Names Data::_names;
GfNames Data::_gfnames;
Cards Data::_cards;
ZellLBs Data::_zellLB;
IrvineLBs Data::_irvineLB;
QuistisLBs Data::_quistisLB;
RinoaLBs Data::_rinoaLB;
Ennemies Data::_ennemies;

void Abilities::fillList()
{
	_list << QString("") << QObject::tr("HP-J") << QObject::tr("Str-J") << QObject::tr("Vit-J") << QObject::tr("Mag-J") << QObject::tr("Spr-J")
		  << QObject::tr("Spd-J") << QObject::tr("Eva-J") << QObject::tr("Hit-J") << QObject::tr("Luck-J") << QObject::tr("Elem-Atk-J")
		  << QObject::tr("ST-Atk-J") << QObject::tr("Elem-Def-J") << QObject::tr("ST-Def-J") << QObject::tr("Elem-Defx2") << QObject::tr("Elem-Defx4")
		  << QObject::tr("ST-Def-Jx2") << QObject::tr("ST-Def-Jx4") << QObject::tr("Abilityx3") << QObject::tr("Abilityx4") << QObject::tr("Magic")
		  << QObject::tr("GF") << QObject::tr("Draw") << QObject::tr("Item") << "???" << QObject::tr("Card")
		  << QObject::tr("Doom") << QObject::tr("Mad Rush") << QObject::tr("Treatment") << QObject::tr("Defend") << QObject::tr("Darkside")
		  << QObject::tr("Recover") << QObject::tr("Absorb") << QObject::tr("Revive") << QObject::tr("LV Down") << QObject::tr("LV Up")
		  << QObject::tr("Kamikaze") << QObject::tr("Devour") << QObject::tr("MiniMog") << QObject::tr("HP+20%") << QObject::tr("HP+40%")
		  << QObject::tr("HP+80%") << QObject::tr("Str+20%") << QObject::tr("Str+40%") << QObject::tr("Str+60%") << QObject::tr("Vit+20%")
		  << QObject::tr("Vit+40%") << QObject::tr("Vit+60%") << QObject::tr("Mag+20%") << QObject::tr("Mag+40%") << QObject::tr("Mag+60%")
		  << QObject::tr("Spr+20%") << QObject::tr("Spr+40%") << QObject::tr("Spr+60%") << QObject::tr("Spd+20%") << QObject::tr("Spd+40%")
		  << QObject::tr("Eva+30%") << QObject::tr("Luck+50%") << QObject::tr("Mug") << QObject::tr("Med Data") << QObject::tr("Counter")
		  << QObject::tr("Return Damage") << QObject::tr("Cover") << QObject::tr("Initiative") << QObject::tr("Move-HP Up") << QObject::tr("HP Bonus","ability")
		  << QObject::tr("Str Bonus","ability") << QObject::tr("Vit Bonus","ability") << QObject::tr("Mag Bonus","ability") << QObject::tr("Spr Bonus","ability") << QObject::tr("Auto-Protect")
		  << QObject::tr("Auto-Shell") << QObject::tr("Auto-Reflect") << QObject::tr("Auto-Haste") << QObject::tr("Auto-Potion") << QObject::tr("Expendx2-1")
		  << QObject::tr("Expendx3-1") << QObject::tr("Ribbon", "ability") << QObject::tr("Alert") << QObject::tr("Move-Find") << QObject::tr("Enc-Half")
		  << QObject::tr("Enc-None") << QObject::tr("Rare Item") << QObject::tr("SumMag+10%") << QObject::tr("SumMag+20%") << QObject::tr("SumMag+30%")
		  << QObject::tr("SumMag+40%") << QObject::tr("GFHP+10%") << QObject::tr("GFHP+20%") << QObject::tr("GFHP+30%") << QObject::tr("GFHP+40%")
		  << QObject::tr("Boost") << QObject::tr("Haggle") << QObject::tr("Sell-High") << QObject::tr("Familiar") << QObject::tr("Call Shop")
		  << QObject::tr("Junk Shop") << QObject::tr("T Mag-RF") << QObject::tr("I Mag-RF") << QObject::tr("F Mag-RF") << QObject::tr("L Mag-RF")
		  << QObject::tr("Time Mag-RF") << QObject::tr("ST Mag-RF") << QObject::tr("Supt Mag-RF") << QObject::tr("Forbid Mag-RF") << QObject::tr("Recov Med-RF")
		  << QObject::tr("ST Med-RF") << QObject::tr("Ammo-RF") << QObject::tr("Tool-RF") << QObject::tr("Forbid Med-RF") << QObject::tr("GFRecov Med-RF")
		  << QObject::tr("GFAbl Med-RF") << QObject::tr("Mid Mag-RF") << QObject::tr("High Mag-RF") << QObject::tr("Med LV Up") << QObject::tr("Card Mod");
}

void Magics::fillList()
{
	_list << QString("-") << QObject::tr("Fire") << QObject::tr("Fira") << QObject::tr("Firaga") << QObject::tr("Blizzard") << QObject::tr("Blizzara")
		  << QObject::tr("Blizzaga") << QObject::tr("Thunder") << QObject::tr("Thundara") << QObject::tr("Thundaga") << QObject::tr("Water") << QObject::tr("Aero") << QObject::tr("Bio")
		  << QObject::tr("Demi") << QObject::tr("Holy") << QObject::tr("Flare") << QObject::tr("Meteor") << QObject::tr("Quake") << QObject::tr("Tornado") << QObject::tr("Ultima")
		  << QObject::tr("Apocalypse") << QObject::tr("Cure") << QObject::tr("Cura") << QObject::tr("Curaga") << QObject::tr("Life") << QObject::tr("Full-life") << QObject::tr("Regen") << QObject::tr("Esuna")
		  << QObject::tr("Dispel") << QObject::tr("Protect") << QObject::tr("Shell") << QObject::tr("Reflect") << QObject::tr("Aura") << QObject::tr("Double") << QObject::tr("Triple") << QObject::tr("Haste")
		  << QObject::tr("Slow") << QObject::tr("Stop") << QObject::tr("Blind") << QObject::tr("Confuse") << QObject::tr("Sleep") << QObject::tr("Silence") << QObject::tr("Break") << QObject::tr("Death")
		  << QObject::tr("Drain") << QObject::tr("Pain") << QObject::tr("Berserk") << QObject::tr("Float") << QObject::tr("Zombie") << QObject::tr("Meltdown") << QObject::tr("Scan") << QObject::tr("Full-cure")
		  << QObject::tr("Wall") << QObject::tr("Rapture") << QObject::tr("Percent") << QObject::tr("Catastrophe") << QObject::tr("The End");
}

void Items::fillList()
{
	_list << "" << QObject::tr("Potion") << QObject::tr("Potion+") << QObject::tr("Hi-Potion") << QObject::tr("Hi-Potion+") << QObject::tr("X-Potion")
		  << QObject::tr("Mega-Potion") << QObject::tr("Phoenix Down") << QObject::tr("Mega Phoenix") << QObject::tr("Elixir") << QObject::tr("Megalixir") << QObject::tr("Antidote")
		  << QObject::tr("Soft") << QObject::tr("Eye Drops") << QObject::tr("Echo Screen") << QObject::tr("Holy Water") << QObject::tr("Remedy") << QObject::tr("Remedy+")
		  << QObject::tr("Hero-trial") << QObject::tr("Hero") << QObject::tr("Holy War-trial") << QObject::tr("Holy War") << QObject::tr("Shell Stone")
		  << QObject::tr("Protect Stone") << QObject::tr("Aura Stone") << QObject::tr("Death Stone") << QObject::tr("Holy Stone") << QObject::tr("Flare Stone")
		  << QObject::tr("Meteor Stone") << QObject::tr("Ultima Stone") << QObject::tr("Gysahl Greens") << QObject::tr("Phoenix Pinion","item") << QObject::tr("Friendship")
		  << QObject::tr("Tent") << QObject::tr("Pet House") << QObject::tr("Cottage") << QObject::tr("G-Potion") << QObject::tr("G-Hi-Potion")
		  << QObject::tr("G-Mega-Potion") << QObject::tr("G-Returner") << QObject::tr("Rename Card") << QObject::tr("Amnesia Greens") << QObject::tr("HP-J Scroll")
		  << QObject::tr("Str-J Scroll") << QObject::tr("Vit-J Scroll") << QObject::tr("Mag-J Scroll") << QObject::tr("Spr-J Scroll") << QObject::tr("Spd-J Scroll")
		  << QObject::tr("Luck-J Scroll") << QObject::tr("Aegis Amulet") << QObject::tr("Elem Atk") << QObject::tr("Elem Guard") << QObject::tr("Status Atk")
		  << QObject::tr("Status Guard") << QObject::tr("Rosetta Stone") << QObject::tr("Magic Scroll") << QObject::tr("GF Scroll") << QObject::tr("Draw Scroll")
		  << QObject::tr("Item Scroll") << QObject::tr("Gambler Spirit") << QObject::tr("Healing Ring") << QObject::tr("Phoenix Spirit") << QObject::tr("Med Kit") << QObject::tr("Bomb Spirit")
		  << QObject::tr("Hungry Cookpot") << QObject::tr("Mog's Amulet") << QObject::tr("Steel Pipe") << QObject::tr("Star Fragment") << QObject::tr("Energy Crystal") << QObject::tr("Samantha Soul")
		  << QObject::tr("Healing Mail") << QObject::tr("Silver Mail", "item1") << QObject::tr("Gold Armor") << QObject::tr("Diamond Armor") << QObject::tr("Regen Ring") << QObject::tr("Giant's Ring")
		  << QObject::tr("Gaea's Ring") << QObject::tr("Strength Love") << QObject::tr("Power Wrist") << QObject::tr("Hyper Wrist") << QObject::tr("Turtle Shell") << QObject::tr("Orihalcon")
		  << QObject::tr("Adamantine") << QObject::tr("Rune Armlet") << QObject::tr("Force Armlet") << QObject::tr("Magic Armlet") << QObject::tr("Circlet") << QObject::tr("Hypno Crown")
		  << QObject::tr("Royal Crown") << QObject::tr("Jet Engine") << QObject::tr("Rocket Engine") << QObject::tr("Moon Curtain") << QObject::tr("Steel Curtain") << QObject::tr("Glow Curtain")
		  << QObject::tr("Accelerator") << QObject::tr("Monk's Code") << QObject::tr("Knight's Code") << QObject::tr("Doc's Code") << QObject::tr("Hundred Needles") << QObject::tr("Three Stars")
		  << QObject::tr("Ribbon", "item") << QObject::tr("Normal Ammo") << QObject::tr("Shotgun Ammo") << QObject::tr("Dark Ammo") << QObject::tr("Fire Ammo")
		  << QObject::tr("Demolition Ammo") << QObject::tr("Fast Ammo") << QObject::tr("AP Ammo") << QObject::tr("Pulse Ammo") << QObject::tr("M-Stone Piece")
		  << QObject::tr("Magic Stone") << QObject::tr("Wizard Stone") << QObject::tr("Ochu Tentacle") << QObject::tr("Healing Water") << QObject::tr("Cockatrice Pinion")
		  << QObject::tr("Zombie Powder") << QObject::tr("Lightweight") << QObject::tr("Sharp Spike") << QObject::tr("Screw") << QObject::tr("Saw Blade")
		  << QObject::tr("Mesmerize Blade") << QObject::tr("Vampire Fang") << QObject::tr("Fury Fragment") << QObject::tr("Betrayal Sword") << QObject::tr("Sleep Powder")
		  << QObject::tr("Life Ring") << QObject::tr("Dragon Fang") << QObject::tr("Spider Web") << QObject::tr("Coral Fragment") << QObject::tr("Curse Spike") << QObject::tr("Black Hole")
		  << QObject::tr("Water Crystal") << QObject::tr("Missile") << QObject::tr("Mystery Fluid") << QObject::tr("Running Fire") << QObject::tr("Inferno Fang") << QObject::tr("Malboro Tentacle")
		  << QObject::tr("Whisper") << QObject::tr("Laser Cannon") << QObject::tr("Barrier", "item2") << QObject::tr("Power Generator") << QObject::tr("Dark Matter") << QObject::tr("Bomb Fragment")
		  << QObject::tr("Red Fang") << QObject::tr("Arctic Wind") << QObject::tr("North Wind") << QObject::tr("Dynamo Stone") << QObject::tr("Shear Feather") << QObject::tr("Venom Fang")
		  << QObject::tr("Steel Orb") << QObject::tr("Moon Stone") << QObject::tr("Dino Bone") << QObject::tr("Windmill") << QObject::tr("Dragon Skin") << QObject::tr("Fish Fin")
		  << QObject::tr("Dragon Fin") << QObject::tr("Silence Powder") << QObject::tr("Poison Powder") << QObject::tr("Dead Spirit") << QObject::tr("Chef's Knife") << QObject::tr("Cactus Thorn")
		  << QObject::tr("Shaman Stone") << QObject::tr("Fuel") << QObject::tr("Girl Next Door") << QObject::tr("Sorceress' Letter") << QObject::tr("Chocobo's Tag")
		  << QObject::tr("Pet Nametag") << QObject::tr("Solomon Ring") << QObject::tr("Magical Lamp") << QObject::tr("HP Up","item") << QObject::tr("Str Up","item")
		  << QObject::tr("Vit Up","item") << QObject::tr("Mag Up","item") << QObject::tr("Spr Up","item") << QObject::tr("Spd Up","item") << QObject::tr("Luck Up","item")
		  << QObject::tr("LuvLuv G") << QObject::tr("Weapons Mon 1st") << QObject::tr("Weapons Mon Mar") << QObject::tr("Weapons Mon Apr") << QObject::tr("Weapons Mon May")
		  << QObject::tr("Weapons Mon Jun") << QObject::tr("Weapons Mon Jul") << QObject::tr("Weapons Mon Aug") << QObject::tr("Combat King 001") << QObject::tr("Combat King 002")
		  << QObject::tr("Combat King 003") << QObject::tr("Combat King 004") << QObject::tr("Combat King 005") << QObject::tr("Pet Pals Vol.1") << QObject::tr("Pet Pals Vol.2")
		  << QObject::tr("Pet Pals Vol.3") << QObject::tr("Pet Pals Vol.4") << QObject::tr("Pet Pals Vol.5") << QObject::tr("Pet Pals Vol.6") << QObject::tr("Occult Fan I")
		  << QObject::tr("Occult Fan II") << QObject::tr("Occult Fan III") << QObject::tr("Occult Fan IV");
}

void Locations::fillList()
{
	_list << QString("???") << QObject::tr("Balamb- Alcauld Plains","1") << QObject::tr("Balamb- Gaulg Mountains","2") << QObject::tr("Balamb- Rinaul Coast","3") << QObject::tr("Balamb- Raha Cape","4") << QObject::tr("Timber- Roshfall Forest","5") << QObject::tr("Timber- Mandy Beach","6") << QObject::tr("Timber- Obel Lake","7") << QObject::tr("Timber- Lanker Plains","8") << QObject::tr("Timber- Nanchucket Island","9") << QObject::tr("Timber- Yaulny Canyon","10") << QObject::tr("Dollet- Hasberry Plains","11") << QObject::tr("Dollet- Holy Glory Cape","12") << QObject::tr("Dollet- Long Horn Island","13") << QObject::tr("Dollet- Malgo Peninsula","14") << QObject::tr("Galbadia- Monterosa Plateau","15")
		  << QObject::tr("Galbadia- Lallapalooza Canyon","16") << QObject::tr("Timber- Shenand Hill","17") << QObject::tr("Galbadia- Gotland Peninsula","18") << QObject::tr("Island Closest to Hell","19") << QObject::tr("Great Plains of Galbadia","20") << QObject::tr("Galbadia- Wilburn Hill","21") << QObject::tr("Galbadia- Rem Archipelago","22") << QObject::tr("Galbadia- Dingo Desert","23") << QObject::tr("Winhill- Winhill Bluffs","24") << QObject::tr("Winhill- Humphrey Archipelago","25") << QObject::tr("Trabia- Winter Island","26") << QObject::tr("Trabia- Sorbald Snowfield","27") << QObject::tr("Trabia- Eldbeak Peninsula","28") << QString("") << QObject::tr("Trabia- Hawkwind Plains","30") << QObject::tr("Trabia- Albatross Archipelago","31")
		  << QObject::tr("Trabia- Bika Snowfield","32") << QObject::tr("Trabia- Thor Peninsula","33") << QString("") << QObject::tr("Trabia- Heath Peninsula","35") << QObject::tr("Trabia- Trabia Crater","36") << QObject::tr("Trabia- Vienne Mountains","37") << QObject::tr("Esthar- Mordred Plains","38") << QObject::tr("Esthar- Nortes Mountains","39") << QObject::tr("Esthar- Fulcura Archipelago","40") << QObject::tr("Esthar- Grandidi Forest","41") << QObject::tr("Esthar- Millefeuille Archipelago","42") << QObject::tr("Great Plains of Esthar","43") << QObject::tr("Esthar City","44") << QObject::tr("Esthar- Great Salt Lake","45") << QObject::tr("Esthar- West Coast","46") << QObject::tr("Esthar- Sollet Mountains","47")
		  << QObject::tr("Esthar- Abadan Plains","48") << QObject::tr("Esthar- Minde Island","49") << QObject::tr("Esthar- Kashkabald Desert","50") << QObject::tr("Island Closest to Heaven","51") << QObject::tr("Esthar- Talle Mountains","52") << QObject::tr("Esthar- Shalmal Peninsula","53") << QObject::tr("Centra- Lolestern Plains","54") << QObject::tr("Centra- Almaj Mountains","55") << QObject::tr("Centra- Lenown Plains","56") << QObject::tr("Centra- Cape of Good Hope","57") << QObject::tr("Centra- Yorn Mountains","58") << QObject::tr("Esthar- Cactuar Island","59") << QObject::tr("Centra- Serengetti Plains","60") << QObject::tr("Centra- Nectar Peninsula","61") << QObject::tr("Centra- Centra Crater","62") << QObject::tr("Centra- Poccarahi Island","63")
		  << QObject::tr("B-Garden- Library","64") << QObject::tr("B-Garden- Front Gate","65") << QObject::tr("B-Garden- Classroom","66") << QObject::tr("B-Garden- Cafeteria","67") << QObject::tr("B-Garden- MD Level","68") << QObject::tr("B-Garden- 2F Hallway","69") << QObject::tr("B-Garden- Hall","70") << QObject::tr("B-Garden- Infirmary","71") << QObject::tr("B-Garden- Dormitory Double","72") << QObject::tr("B-Garden- Dormitory Single","73") << QObject::tr("B-Garden- Headmaster's Office","74") << QObject::tr("B-Garden- Parking Lot","75") << QObject::tr("B-Garden- Ballroom","76") << QObject::tr("B-Garden- Quad","77") << QObject::tr("B-Garden- Training Center","78") << QObject::tr("B-Garden- Secret Area","79")
		  << QObject::tr("B-Garden- Hallway","80") << QObject::tr("B-Garden- Master Room","81") << QObject::tr("B-Garden- Deck","82") << QObject::tr("Balamb- The Dincht's","83") << QObject::tr("Balamb Hotel","84") << QObject::tr("Balamb- Town Square","85") << QObject::tr("Balamb- Station Yard","86") << QObject::tr("Balamb Harbor","87") << QObject::tr("Balamb- Residence","88") << QObject::tr("Train","89") << QObject::tr("Car","90") << QObject::tr("Inside Ship","91") << QObject::tr("Fire Cavern","92") << QObject::tr("Dollet- Town Square","93") << QObject::tr("Dollet- Lapin Beach","94") << QObject::tr("Dollet Harbor","95")
		  << QObject::tr("Dollet Pub","96") << QObject::tr("Dollet Hotel","97") << QObject::tr("Dollet- Residence","98") << QObject::tr("Dollet- Comm Tower","99") << QObject::tr("Dollet- Mountain Hideout","100") << QObject::tr("Timber- City Square","101") << QObject::tr("Timber TV Station","102") << QObject::tr("Timber- Forest Owls' Base","103") << QObject::tr("Timber Pub","104") << QObject::tr("Timber Hotel","105") << QObject::tr("Timber- Train","106") << QObject::tr("Timber- Residence","107") << QObject::tr("Timber- TV Screen","108") << QObject::tr("Timber- Editorial Department","109") << QObject::tr("Timber Forest","110") << QObject::tr("Galbadia Garden- Front Gate","111")
		  << QObject::tr("G-Garden- Station","112") << QObject::tr("G-Garden- Hall","113") << QObject::tr("G-Garden- Hallway","114") << QObject::tr("G-Garden- Reception Room","115") << QObject::tr("G-Garden- Classroom","116") << QObject::tr("G-Garden- Clubroom","117") << QObject::tr("G-Garden- Dormitory","118") << QObject::tr("G-Garden- Elevator Hall","119") << QObject::tr("G-Garden- Master Room","120") << QObject::tr("G-Garden- Auditorium","121") << QObject::tr("G-Garden- Athletic Track","122") << QObject::tr("G-Garden- Stand","123") << QObject::tr("G-Garden- Back Entrance","124") << QObject::tr("G-Garden- Gymnasium","125") << QObject::tr("Deling- Presidential Residence","126") << QObject::tr("Deling City- Caraway's Mansion","127")
		  << QObject::tr("Deling City- Station Yard","128") << QObject::tr("Deling City- City Square","129") << QObject::tr("Deling City- Hotel","130") << QObject::tr("Deling City- Club","131") << QObject::tr("Deling City- Gateway","132") << QObject::tr("Deling City- Parade","133") << QObject::tr("Deling City- Sewer","134") << QObject::tr("Galbadia D-District Prison","135") << QObject::tr("Desert","136") << QObject::tr("Galbadia Missile Base","137") << QObject::tr("Winhill Village","138") << QObject::tr("Winhill Pub","139") << QObject::tr("Winhill- Vacant House","140") << QObject::tr("Winhill- Mansion","141") << QObject::tr("Winhill- Residence","142") << QObject::tr("Winhill- Hotel","143")
		  << QObject::tr("Winhill- Car","144") << QObject::tr("Tomb of the Unknown King","145") << QObject::tr("Fishermans Horizon","146") << QObject::tr("FH- Residential Area","147") << QObject::tr("FH- Sun Panel","148") << QObject::tr("FH- Mayor's Residence","149") << QObject::tr("FH- Factory","150") << QObject::tr("FH- Festival Grounds","151") << QObject::tr("FH- Hotel","152") << QObject::tr("FH- Residence","153") << QObject::tr("FH- Station Yard","154") << QObject::tr("FH- Horizon Bridge","155") << QObject::tr("FH- Seaside Station","156") << QObject::tr("FH- Great Salt Lake","157") << QObject::tr("FH- Mystery Building","158") << QObject::tr("Esthar- City","159")
		  << QObject::tr("Esthar- Odine's Laboratory","160") << QObject::tr("Esthar- Airstation","161") << QObject::tr("Lunatic Pandora Approaching","162") << QObject::tr("Esthar- Presidential Palace","163") << QObject::tr("Presidential Palace- Hall","164") << QObject::tr("Presidential Palace- Hallway","165") << QObject::tr("Presidential Palace- Office","166") << QObject::tr("Dr. Odine's Laboratory- Lobby","167") << QObject::tr("Dr. Odine's Laboratory- Lab","168") << QObject::tr("Deleted","169") << QObject::tr("Lunar Gate","170") << QObject::tr("Lunar Gate- Concourse","171") << QObject::tr("Lunar Gate- Deep Freeze","172") << QObject::tr("Esthar Sorceress Memorial","173") << QObject::tr("Sorceress Memorial- Entrance","174") << QObject::tr("Sorceress Memorial- Pod","175")
		  << QObject::tr("Sorceress Memorial- Ctrl Room","176") << QObject::tr("Tears' Point","177") << QObject::tr("Lunatic Pandora Laboratory","178") << QObject::tr("Emergency Landing Zone","179") << QObject::tr("Spaceship Landing Zone","180") << QObject::tr("Lunatic Pandora","181") << QObject::tr("Centra- Excavation Site","182") << QObject::tr("Edea's House","183") << QObject::tr("Edea's House- Playroom","184") << QObject::tr("Edea's House- Bedroom","185") << QObject::tr("Edea's House- Backyard","186") << QObject::tr("Edea's House- Oceanside","187") << QObject::tr("Edea's House- Flower Field","188") << QObject::tr("Centra Ruins","189") << QObject::tr("Trabia Garden- Front Gate","190") << QObject::tr("T-Garden- Cemetery","191")
		  << QObject::tr("T-Garden- Garage","192") << QObject::tr("T-Garden- Festival Stage","193") << QObject::tr("T-Garden- Classroom","194") << QObject::tr("T-Garden- Athletic Ground","195") << QObject::tr("Mystery Dome","196") << QObject::tr("Shumi Village- Desert Village","197") << QObject::tr("Shumi Village- Elevator","198") << QObject::tr("Shumi Village- Village","199") << QObject::tr("Shumi Village- Residence","200") << QObject::tr("Shumi Village- Residence","201") << QObject::tr("Shumi Village- Residence","202") << QObject::tr("Shumi Village- Hotel","203") << QObject::tr("Trabia Canyon","204") << QObject::tr("White SeeD Ship","205") << QObject::tr("White SeeD Ship","206") << QObject::tr("White SeeD Ship- Cabin","207")
		  << QObject::tr("Ragnarok- Cockpit","208") << QObject::tr("Ragnarok- Passenger Seat","209") << QObject::tr("Ragnarok- Aisle","210") << QObject::tr("Ragnarok- Hangar","211") << QObject::tr("Ragnarok- Entrance","212") << QObject::tr("Ragnarok- Air Room","213") << QObject::tr("Ragnarok- Space Hatch","214") << QObject::tr("Deep Sea Research Center","215") << QObject::tr("Deep Sea Research Center- Lb","216") << QObject::tr("Deep Sea Research Center- Lv","217") << QObject::tr("Deep Sea Deposit","218") << QObject::tr("Lunar Base- Control Room","219") << QObject::tr("Lunar Base- Medical Room","220") << QObject::tr("Lunar Base- Pod","221") << QObject::tr("Lunar Base- Dock","222") << QObject::tr("Lunar Base- Passageway","223")
		  << QObject::tr("Lunar Base- Locker","224") << QObject::tr("Lunar Base- Residential Zone","225") << QObject::tr("Outer Space","226") << QObject::tr("Chocobo Forest","227") << QObject::tr("Wilderness","228") << QObject::tr("Ultimecia Castle- Hall","229") << QObject::tr("Ultimecia Castle- Grand Hall","230") << QObject::tr("Ultimecia Castle- Terrace","231") << QObject::tr("Ultimecia Castle- Wine Cellar","232") << QObject::tr("Ultimecia Castle- Passageway","233") << QObject::tr("Ultimecia Castle- Elevator Hall","234") << QObject::tr("Ultimecia Castle- Stairway Hall","235") << QObject::tr("Ultimecia Castle- Treasure Rm","236") << QObject::tr("Ultimecia Castle- Storage Room","237") << QObject::tr("Ultimecia Castle- Art Gallery","238") << QObject::tr("Ultimecia Castle- Flood Gate","239")
		  << QObject::tr("Ultimecia Castle- Armory","240") << QObject::tr("Ultimecia Castle- Prison Cell","241") << QObject::tr("Ultimecia Castle- Waterway","242") << QObject::tr("Ultimecia Castle- Courtyard","243") << QObject::tr("Ultimecia Castle- Chapel","244") << QObject::tr("Ultimecia Castle- Clock Tower","245") << QObject::tr("Ultimecia Castle- Master Room","246") << QString("???") << QObject::tr("Ultimecia Castle","248") << QObject::tr("Commencement Room","249") << QObject::tr("Queen","250") << QString("???") << QString("???") << QString("???") << QString("???") << QString("???");
}

void Cities::fillList()
{
	_list << QObject::tr("Balamb City") << QObject::tr("Deling City") << QObject::tr("Shumi Village")
	      << QObject::tr("Winhill") << QObject::tr("Dollet") << QObject::tr("Fishermans Horizon")
	      << QObject::tr("Lunar Gate") << QObject::tr("Esthar City") << QObject::tr("Timber")
	      << QObject::tr("Balamb Garden") << QObject::tr("Galbadia Garden") << QObject::tr("Trabia Garden") << QObject::tr("Centra Ruins")
	      << QObject::tr("Edea's House") << QObject::tr("Great Salt Lake") << QObject::tr("Beginner's Forest")
	      << QObject::tr("Basic Forest") << QObject::tr("Roaming Forest") << QObject::tr("Chocobo Sanctuary")
	      << QObject::tr("Enclosed Forest") << QObject::tr("Fun Forest") << QObject::tr("Forest of Solitude")
	      << QObject::tr("Landing site");
}

void Weapons::fillList()
{
	_list << QObject::tr("Revolver") << QObject::tr("Shear Trigger") << QObject::tr("Cutting Trigger") << QObject::tr("Flame Saber") << QObject::tr("Twin Lance") << QObject::tr("Punishment") << QObject::tr("Lion Heart")
		  << QObject::tr("Metal Knuckle") << QObject::tr("Maverick") << QObject::tr("Gauntlet") << QObject::tr("Ehrgeiz")
		  << QObject::tr("Valiant") << QObject::tr("Ulysses") << QObject::tr("Bismarck") << QObject::tr("Exeter")
		  << QObject::tr("Chain Whip") << QObject::tr("Slaying Tail") << QObject::tr("Red Scorpion") << QObject::tr("Save the Queen")
		  << QObject::tr("Pinwheel") << QObject::tr("Valkyrie") << QObject::tr("Rising Sun") << QObject::tr("Cardinal") << QObject::tr("Shooting Star")
		  << QObject::tr("Flail") << QObject::tr("Morning Star") << QObject::tr("Crescent Wish") << QObject::tr("Strange Vision")
		  << QObject::tr("Hyperion") << QObject::tr("None") << QObject::tr("Machine Gun") << QObject::tr("Katal") << QObject::tr("Harpoon");
}

void Names::fillList()
{
	_list << QObject::tr("Squall") << QObject::tr("Zell") << QObject::tr("Irvine") << QObject::tr("Quistis") << QObject::tr("Rinoa")
		  << QObject::tr("Selphie") << QObject::tr("Seifer") << QObject::tr("Edea") << QObject::tr("Laguna") << QObject::tr("Kiros")
		  << QObject::tr("Ward") << "" << QObject::tr("Griever") << QObject::tr("MiniMog") << QObject::tr("Boko") << QObject::tr("Angelo");
}

void GfNames::fillList()
{
	_list << QObject::tr("Quezacotl","gf") << QObject::tr("Shiva","gf") << QObject::tr("Ifrit","gf") << QObject::tr("Siren","gf")
		  << QObject::tr("Brothers","gf") << QObject::tr("Diablos","gf") << QObject::tr("Carbuncle","gf") << QObject::tr("Leviathan","gf")
		  << QObject::tr("Pandemona","gf") << QObject::tr("Cerberus","gf") << QObject::tr("Alexander","gf") << QObject::tr("Doomtrain","gf")
		  << QObject::tr("Bahamut","gf") << QObject::tr("Cactuar","gf") << QObject::tr("Tonberry","gf") << QObject::tr("Eden","gf");
}

void ZellLBs::fillList()
{
	_list << QObject::tr("Punch Rush") << QObject::tr("Booya") << QObject::tr("Heel Drop") << QObject::tr("Mach Kick") << QObject::tr("Dolphin Blow")
		  << QObject::tr("Meteor Strike") << QObject::tr("Burning Rave") << QObject::tr("Meteor Barret") << QObject::tr("Different Beat") << QObject::tr("My Final Heaven");
}

void IrvineLBs::fillList()
{
	_list << QObject::tr("Normal Shot") << QObject::tr("Scatter Shot") << QObject::tr("Dark Shot") << QObject::tr("Flame Shot")
		  << QObject::tr("Canister Shot") << QObject::tr("Quick Shot") << QObject::tr("Armor Shot") << QObject::tr("Hyper Shot");
}

void QuistisLBs::fillList()
{
	_list << QObject::tr("Laser Eye") << QObject::tr("Ultra Waves") << QObject::tr("Electrocute") << QObject::tr("LV?Death")
		  << QObject::tr("Degenerator") << QObject::tr("Aqua Breath") << QObject::tr("Micro Missiles") << QObject::tr("Acid")
		  << QObject::tr("Gatling Gun") << QObject::tr("Fire Breath") << QObject::tr("Bad Breath") << QObject::tr("White Wind")
		  << QObject::tr("Homing Laser") << QObject::tr("Mighty Guard") << QObject::tr("Ray-Bomb") << QObject::tr("Shockwave Pulsar");
}

void RinoaLBs::fillList()
{
	_list << QObject::tr("Rush") << QObject::tr("Recover") << QObject::tr("Reverse") << QObject::tr("Search")
		  << QObject::tr("Cannon") << QObject::tr("Strike") << QObject::tr("Invincible Moon") << QObject::tr("Wishing Star");
}

void Cards::fillList()
{
	_list << QObject::tr("Geezard") << QObject::tr("Funguar") << QObject::tr("Bite Bug") << QObject::tr("Red Bat") << QObject::tr("Blobra") << QObject::tr("Gayla")
		  << QObject::tr("Gesper") << QObject::tr("Fastitocalon") << QObject::tr("Blood Soul") << QObject::tr("Caterchipillar") << QObject::tr("Cockatrice") << QObject::tr("Grat")
		  << QObject::tr("Buel") << QObject::tr("Mesmerize") << QObject::tr("Glacial Eye") << QObject::tr("Belhelmel") << QObject::tr("Thrustaevis") << QObject::tr("Anacondaur")
		  << QObject::tr("Creeps") << QObject::tr("Grendel") << QObject::tr("Jelleye") << QObject::tr("Grand Mantis") << QObject::tr("Forbidden") << QObject::tr("Armadodo")
		  << QObject::tr("Tri-Face") << QObject::tr("Fastitocalon-F") << QObject::tr("Snow Lion") << QObject::tr("Ochu") << QObject::tr("SAM08G")
		  << QObject::tr("Death Claw") << QObject::tr("Cactuar","card") << QObject::tr("Tonberry","card") << QObject::tr("Abyss Worm") << QObject::tr("Turtapod") << QObject::tr("Vysage")
		  << QObject::tr("T-Rexaur") << QObject::tr("Bomb") << QObject::tr("Blitz") << QObject::tr("Wendigo") << QObject::tr("Torama") << QObject::tr("Imp")
		  << QObject::tr("Blue Dragon") << QObject::tr("Adamantoise") << QObject::tr("Hexadragon") << QObject::tr("Iron Giant") << QObject::tr("Behemoth") << QObject::tr("Chimera")
		  << QObject::tr("PuPu") << QObject::tr("Elastoid") << QObject::tr("GIM47N") << QObject::tr("Malboro") << QObject::tr("Ruby Dragon") << QObject::tr("Elnoyle")
		  << QObject::tr("Tonberry King") << QObject::tr("Wedge, Biggs") << QObject::tr("Fujin, Raijin") << QObject::tr("Elvoret") << QObject::tr("X-ATM092")
		  << QObject::tr("Granaldo") << QObject::tr("Gerogero") << QObject::tr("Iguion") << QObject::tr("Abadon") << QObject::tr("Trauma") << QObject::tr("Oilboyle")
		  << QObject::tr("Shumi") << QObject::tr("Krysta") << QObject::tr("Propagator") << QObject::tr("Jumbo Cactuar") << QObject::tr("Tri-Point") << QObject::tr("Gargantua")
		  << QObject::tr("Mobile Type 8") << QObject::tr("Sphinxara") << QObject::tr("Tiamat") << QObject::tr("BGH251F2") << QObject::tr("Red Giant") << QObject::tr("Catoblepas")
		  << QObject::tr("Ultima Weapon") << QObject::tr("Chubby Chocobo","card") << QObject::tr("Angelo","card") << QObject::tr("Gilgamesh","card") << QObject::tr("MiniMog","card") << QObject::tr("Chicobo","card")
		  << QObject::tr("Quezacotl","card") << QObject::tr("Shiva","card") << QObject::tr("Ifrit","card") << QObject::tr("Siren","card") << QObject::tr("Sacred","card") << QObject::tr("Minotaur","card")
		  << QObject::tr("Carbuncle","card") << QObject::tr("Diablos","card") << QObject::tr("Leviathan","card") << QObject::tr("Odin","card") << QObject::tr("Pandemona","card") << QObject::tr("Cerberus")
		  << QObject::tr("Alexander","card") << QObject::tr("Phoenix","card") << QObject::tr("Bahamut","card") << QObject::tr("Doomtrain","card") << QObject::tr("Eden","card") << QObject::tr("Ward")
		  << QObject::tr("Kiros") << QObject::tr("Laguna") << QObject::tr("Selphie") << QObject::tr("Quistis") << QObject::tr("Irvine") << QObject::tr("Zell")
		  << QObject::tr("Rinoa") << QObject::tr("Edea") << QObject::tr("Seifer") << QObject::tr("Squall");
}

void Ennemies::fillList()
{
	_list << QObject::tr("Dummy", "Ennemy") << QObject::tr("GIM52A", "Ennemy") << QObject::tr("Blobra", "Ennemy") << QObject::tr("Thrustaevis", "Ennemy")
		  << QObject::tr("Geezard", "Ennemy") << QObject::tr("Belhelmel", "Ennemy") << QObject::tr("Glacial Eye", "Ennemy") << QObject::tr("SAM08G", "Ennemy")
		  << QObject::tr("GIM47N", "Ennemy") << QObject::tr("Mesmerize", "Ennemy") << QObject::tr("Buel", "Ennemy") << QObject::tr("Sphinxaur", "Ennemy")
		  << QObject::tr("Sphinxara", "Ennemy") << QObject::tr("Snow Lion", "Ennemy") << QObject::tr("Anacondaur", "Ennemy") << QObject::tr("Grat", "Ennemy")
		  << QObject::tr("Cockatrice", "Ennemy") << QObject::tr("Caterchipillar", "Ennemy") << QObject::tr("Red Bat", "Ennemy") << QObject::tr("Blitz", "Ennemy")
		  << QObject::tr("Fastitocalon", "Ennemy") << QObject::tr("Fastitocalon-F", "Ennemy") << QObject::tr("Gesper", "Ennemy") << QObject::tr("Creeps", "Ennemy")
		  << QObject::tr("Hexadragon", "Ennemy") << QObject::tr("Blood Soul", "Ennemy") << QObject::tr("Elastoid", "Ennemy") << QObject::tr("Armadodo", "Ennemy")
		  << QObject::tr("Bite Bug", "Ennemy") << QObject::tr("Jelleye", "Ennemy") << QObject::tr("Tri-Point", "Ennemy") << QObject::tr("Turtapod", "Ennemy")
		  << QObject::tr("Wendigo", "Ennemy") << QObject::tr("Gayla", "Ennemy") << QObject::tr("Gerogero", "Ennemy") << QObject::tr("Death Claw", "Ennemy")
		  << QObject::tr("Tri-Face", "Ennemy") << QObject::tr("Grand Mantis", "Ennemy") << QObject::tr("Krysta", "Ennemy") << QObject::tr("Lefty", "Ennemy")
		  << QObject::tr("Righty", "Ennemy") << QObject::tr("Blue Dragon", "Ennemy") << QObject::tr("Forbidden", "Ennemy") << QObject::tr("Bomb", "Ennemy")
		  << QObject::tr("Abyss Worm", "Ennemy") << QObject::tr("Ochu", "Ennemy") << QObject::tr("Adamantoise", "Ennemy") << QObject::tr("Chimera", "Ennemy")
		  << QObject::tr("Malboro", "Ennemy") << QObject::tr("Iron Giant", "Ennemy") << QObject::tr("Behemoth", "Ennemy") << QObject::tr("T-Rexaur", "Ennemy")
		  << QObject::tr("Ruby Dragon", "Ennemy") << QObject::tr("Grendel", "Ennemy") << QObject::tr("Vysage", "Ennemy") << QObject::tr("Cactuar", "Ennemy")
		  << QObject::tr("Tonberry", "Ennemy") << QObject::tr("Torama", "Ennemy") << QObject::tr("Funguar", "Ennemy") << QObject::tr("Imp", "Ennemy")
		  << QObject::tr("PuPu", "Ennemy") << QObject::tr("Ifrit", "Ennemy") << QObject::tr("Minotaur", "Ennemy") << QObject::tr("Sacred", "Ennemy")
		  << QObject::tr("Base Leader", "Ennemy") << QObject::tr("Cerberus", "Ennemy") << QObject::tr("Diablos", "Ennemy") << QObject::tr("Bahamut", "Ennemy")
		  << QObject::tr("NORG Pod", "Ennemy") << QObject::tr("Garden Faculty", "Ennemy") << QObject::tr("Odin", "Ennemy") << QObject::tr("G-Soldier", "Ennemy")
		  << QObject::tr("Elite Soldier", "Ennemy") << QObject::tr("Wedge (1)", "Ennemy") << QObject::tr("Biggs (1)", "Ennemy") << QObject::tr("Fake President", "Ennemy")
		  << QObject::tr("Guard", "Ennemy") << QObject::tr("NORG", "Ennemy") << QObject::tr("Esthar Soldier", "Ennemy") << QObject::tr("Esthar Soldier", "Ennemy")
		  << QObject::tr("Right Orb", "Ennemy") << QObject::tr("Left Orb", "Ennemy") << QObject::tr("Gunblade (1)", "Ennemy") << QObject::tr("Tonberry King", "Ennemy")
		  << QObject::tr("Jumbo Cactuar", "Ennemy") << QObject::tr("Seifer (1)", "Ennemy") << QObject::tr("Seifer (2)", "Ennemy") << QObject::tr("Seifer (3)", "Ennemy")
		  << QObject::tr("Edea (1)", "Ennemy") << QObject::tr("Propagator (purple)", "Ennemy") << QObject::tr("Ultima Weapon", "Ennemy") << QObject::tr("Elvoret", "Ennemy")
		  << QObject::tr("X-ATM092", "Ennemy") << QObject::tr("Iguion", "Ennemy") << QObject::tr("Gargantua", "Ennemy") << QObject::tr("Granaldo", "Ennemy")
		  << QObject::tr("Raldo", "Ennemy") << QObject::tr("Propagator (green)", "Ennemy") << QObject::tr("Propagator (yellow)", "Ennemy") << QObject::tr("Oilboyle", "Ennemy")
		  << QObject::tr("Edea (2)", "Ennemy") << QObject::tr("BGH251F2 (1)", "Ennemy") << QObject::tr("BGH251F2 (2)", "Ennemy") << QObject::tr("Abadon", "Ennemy")
		  << QObject::tr("Abadon (zombie)", "Ennemy") << QObject::tr("Mobile Type 8", "Ennemy") << QObject::tr("Left Probe", "Ennemy") << QObject::tr("Right Probe", "Ennemy")
		  << QObject::tr("Paratrooper", "Ennemy") << QObject::tr("Trauma", "Ennemy") << QObject::tr("Droma", "Ennemy") << QObject::tr("Propagator (red)", "Ennemy")
		  << QObject::tr("Adel", "Ennemy") << _names->at(RINOA) << QObject::tr("Omega Weapon", "Ennemy") << QObject::tr("Sorceress", "Ennemy")
		  << QObject::tr("Sorceress (2)", "Ennemy") << QObject::tr("Sorceress (3)", "Ennemy") << QObject::tr("UFO?", "Ennemy") << QObject::tr("Fujin (1)", "Ennemy")
		  << QObject::tr("Raijin (1)", "Ennemy") << QObject::tr("Ultimecia (1)", "Ennemy") << _names->at(GRIEVER) << QObject::tr("(No name)", "Ennemy") << QObject::tr("Ultimecia (2)", "Ennemy")
		  << QObject::tr("Helix", "Ennemy") << QObject::tr("Ultimecia (3)", "Ennemy") << QObject::tr("Ultimecia (4)", "Ennemy") << QObject::tr("Seifer (4)", "Ennemy") << QObject::tr("Slapper", "Ennemy")
		  << QObject::tr("Red Giant", "Ennemy") << QObject::tr("Elnoyle", "Ennemy") << QObject::tr("Tiamat", "Ennemy") << QObject::tr("Catoblepas", "Ennemy")
		  << QObject::tr("Wedge (2)", "Ennemy") << QObject::tr("Biggs (2)", "Ennemy") << QObject::tr("Fujin (2)", "Ennemy") << QObject::tr("Raijin (2)", "Ennemy")
		  << QObject::tr("UFO (Mandy Beach)", "Ennemy") << QObject::tr("UFO (Winhill)", "Ennemy") << QObject::tr("UFO (Trabia)", "Ennemy") << QObject::tr("UFO (Kashkabald Desert)", "Ennemy")
		  << QObject::tr("Gunblade (2)", "Ennemy") << QObject::tr("Base Soldier", "Ennemy");
}

void Data::reload()
{
	_abilities.clear();
	_magic.clear();
	_items.clear();
	_locations.clear();
	_cities.clear();
	_weapons.clear();
	_names.clear();
	_gfnames.clear();
	_cards.clear();
	_zellLB.clear();
	_irvineLB.clear();
	_quistisLB.clear();
	_rinoaLB.clear();
	_ennemies.clear();
}

qint8 Data::abilityType(quint8 abilityID)
{
	if (abilityID >= 01 && abilityID <= 19)	return 0;
	if (abilityID >= 20 && abilityID <= 38)	return 1;
	if (abilityID >= 39 && abilityID <= 77)	return 2;
	if (abilityID >= 78 && abilityID <= 82)	return 3;
	if (abilityID >= 83 && abilityID <= 91)	return 4;
	if (abilityID >= 92 && abilityID <= 120)	return 5;
	return 0;
}

quint8 Data::itemType(quint8 itemID)
{
	if (itemID >= 01 && itemID <= 17)	return 0;
	if ((itemID >= 18 && itemID <= 21)
			|| (itemID >= 30 && itemID <= 32)
			|| (itemID >= 165 && itemID <= 168))	return 1;
	if ((itemID >= 22 && itemID <= 29)
			|| (itemID >= 109 && itemID <= 164)
			|| (itemID >= 169 && itemID <= 176))	return 2;
	if (itemID >= 33 && itemID <= 35)	return 5;
	if (itemID >= 36 && itemID <= 100)	return 4;
	if (itemID >= 101 && itemID <= 108)	return 3;
	return 6;
}

//Thanks to Qhimm

const quint8 Data::apsTab[116] =
{
	0,
	50,		//HP-J
	50,		//Str-J
	50,		//Vit-J
	50,		//Mag-J
	50,		//Spr-J
	120,	//Spd-J
	200,	//Eva-J
	120,	//Hit-J
	200,	//Luck-J
	160,	//Elem-Atk-J
	160,	//ST-Atk-J
	100,	//Elem-Def-J
	100,	//ST-Def-J
	130,	//Elem-Defx2
	180,	//Elem-Defx4
	130,	//ST-Def-Jx2
	180,	//ST-Def-Jx4
	150,	//Abilityx3
	200,	//Abilityx4
	1,		//Magic(20)
	1,		//GF
	1,		//Draw
	1,		//Item
	0,		//???
	40,		//Card
	60,		//Doom
	60,		//MadRush
	100,	//Treatment
	100,	//Defend
	100,	//Darkside
	200,	//Recover
	80,		//Absorb
	200,	//Revive
	100,	//LVDown
	100,	//LVUp
	100,	//Kamikaze
	100,	//Devour
	0,		//MiniMog
	60,		//HP+20%(39)
	120,	//HP+40%
	240,	//HP+80%
	60,		//Str+20%
	120,	//Str+40%
	240,	//Str+60%
	60,		//Vit+20%
	120,	//Vit+40%
	240,	//Vit+60%
	60,		//Mag+20%
	120,	//Mag+40%
	240,	//Mag+60%
	60,		//Spr+20%
	120,	//Spr+40%
	240,	//Spr+60%
	150,	//Spd+20%
	200,	//Spd+40%
	150,	//Eva+30%
	200,	//Luck+50%
	200,	//Mug
	200,	//MedData
	200,	//Counter
	0,		//ReturnDamage
	100,	//Cover
	160,	//Initiative
	200,	//MoveHP-Up
	100,	//HPBonus
	100,	//StrBonus
	100,	//VitBonus
	100,	//MagBonus
	100,	//SprBonus
	250,	//Auto-Protect
	250,	//Auto-Shell
	250,	//Auto-Reflect
	250,	//Auto-Haste
	150,	//Auto-Potion
	250,	//Expendx2-1
	250,	//Expendx3-1
	0,		//Ribbon
	200,	//Alert(78)
	40,		//Move-Find
	30,		//Enc-Half
	100,	//Enc-None
	250,	//RareItem
	40,		//SumMag+10%(83)
	70,		//SumMag+20%
	140,	//SumMag+30%
	200,	//SumMag+40%
	40,		//GFHP+10%
	70,		//GFHP+20%
	140,	//GFHP+30%
	200,	//GFHP+40%
	10,		//Boost
	150,	//Haggle(92)
	150,	//Sell-High
	150,	//Familiar
	200,	//CallShop
	150,	//JunkShop
	30,		//TMag-RF
	30,		//IMag-RF
	30,		//FMag-RF
	30,		//LMag-RF
	30,		//TimeMag-RF
	60,		//STMag-RF
	30,		//SuptMag-RF
	200,	//ForbidMag-RF
	30,		//RecovMed-RF
	30,		//STMed-RF
	30,		//Ammo-RF
	30,		//Tool-RF
	200,	//ForbidMed-RF
	30,		//GFRecovMed-RF
	30,		//GFAblMed-RF
	60,		//MidMag-RF
	60,		//HighMag-RF
	120,	//MedLVUp
	80,		//CardMod
};

const quint8 Data::innateAbilities[16][22] =
{
	{//Golgotha
	 83,	// SumMag+10%
	 84,	// SumMag+20%
	 85,	// SumMag+30%
	 87,	// GFHP+10%
	 88,	// GFHP+20%
	 91,	// Boost
	 97,	// T Mag-RF
	 112,// Mid Mag-RF
	 1,	// HP-J
	 48,	// Mag+20%
	 49,	// Mag+40%
	 10,	// Elem-Atk-J
	 3,	// Vit-J
	 12,	// Elem-Def-J
	 14,	// Elem-Defx2
	 25,	// Card
	 115,// Card Mod
	 4,	// Mag-J
	 23,	// Item
	 20,	// Magic
	 21,	// GF
	 22, //Draw
	},
	{//Shiva
	 83,	// SumMag+10%
	 84,	// SumMag+20%
	 85,	// SumMag+30%
	 87,	// GFHP+10%
	 88,	// GFHP+20%
	 23,	//Item
	 91,	//Boost
	 98,	//IMag-RF
	 3,	//Vit-J
	 45,	//Vit+20%
	 46,	//Vit+40%
	 51,	//Spr+20%
	 52,	//Spr+40%
	 12,	//Elem-Def-J
	 14,	//Elem-Defx2
	 2,	//Str-J
	 10,	//Elem-Atk-J
	 26,	//Doom
	 5,	//Spr-J
	 20,	//Magic
	 21,	//GF
	 22, //Draw
	},
	{//Ifrit
	 83,	//SumMag+10%
	 84,	//SumMag+20%
	 85,	//SumMag+30%
	 87,	//GFHP+10%
	 88,	//GFHP+20%
	 89,	//GFHP+30%
	 91,	//Boost
	 99,	//FMag-RF
	 107,//Ammo-RF
	 42,	//Str+20%
	 43,	//Str+40%
	 10,	//Elem-Atk-J
	 66,	//StrBonus
	 1,	//HP-J
	 23,	//Item
	 12,	//Elem-Def-J
	 14,	//Elem-Defx2
	 27,	//MadRush
	 2,	//Str-J
	 20,	//Magic
	 21,	//GF
	 22, //Draw
	},
	{//Ondine
	 87,	//GFHP+10%
	 88,	//GFHP+20%
	 108,//Tool-RF
	 83,	//SumMag+10%
	 84,	//SumMag+20%
	 85,	//SumMag+30%
	 91,	//Boost
	 100,//LMag-RF
	 106,//STMed-RF
	 48,	//Mag+20%
	 49,	//Mag+40%
	 11,	//ST-Atk-J
	 68,	//MagBonus
	 23,	//Item
	 13,	//ST-Def-J
	 16,	//ST-Def-Jx2
	 28,	//Treatment
	 79,	//Move-Find
	 4,	//Mag-J
	 20,	//Magic
	 21,	//GF
	 22, //Draw
	},
	{//Taurus
	 83,	//SumMag+10%
	 84,	//SumMag+20%
	 85,	//SumMag+30%
	 87,	//GFHP+10%
	 88,	//GFHP+20%
	 89,	//GFHP+30%
	 91,	//Boost
	 39,	//HP+20%
	 40,	//HP+40%
	 41,	//HP+80%
	 65,	//HPBonus
	 2,	//Str-J
	 10,	//Elem-Atk-J
	 5,	//Spr-J
	 12,	//Elem-Def-J
	 23,	//Item
	 62,	//Cover
	 29,	//Defend
	 1,	//HP-J
	 20,	//Magic
	 21,	//GF
	 22, //Draw
	},
	{//Nosferatu
	 87,	//GFHP+10%
	 88,	//GFHP+20%
	 89,	//GFHP+30%
	 101,//TimeMag-RF
	 102,//STMag-RF
	 1,	//HP-J
	 39,	//HP+20%
	 40,	//HP+40%
	 41,	//HP+80%
	 4,	//Mag-J
	 48,	//Mag+20%
	 49,	//Mag+40%
	 23,	//Item
	 8,	//Hit-J
	 80,	//Enc-Half
	 81,	//Enc-None
	 30,	//Darkside
	 58,	//Mug
	 18,	//Abilityx3
	 20,	//Magic
	 21,	//GF
	 22, //Draw
	},
	{//Ahuri
	 87,	//GFHP+10%
	 88,	//GFHP+20%
	 89,	//GFHP+30%
	 105,//RecovMed-RF
	 45,	//Vit+20%
	 46,	//Vit+40%
	 67,	//VitBonus
	 1,	//HP-J
	 39,	//HP+20%
	 40,	//HP+40%	(?)
	 4,	//Mag-J
	 11,	//ST-Atk-J
	 13,	//ST-Def-J
	 16,	//ST-Def-Jx2
	 60,	//Counter
	 72,	//Auto-Reflect
	 23,	//Item
	 18,	//Abilityx3
	 3,	//Vit-J
	 20,	//Magic
	 21,	//GF
	 22, //Draw
	},
	{//Leviathan
	 87,	//GFHP+10%
	 88,	//GFHP+20%
	 89,	//GFHP+30%
	 83,	//SumMag+10%
	 84,	//SumMag+20%
	 85,	//SumMag+30%
	 91,	//Boost
	 103,//SuptMag-RF
	 110,//GFRecovMed-RF
	 51,	//Spr+20%
	 52,	//Spr+40%
	 69,	//SprBonus
	 5,	//Spr-J
	 14,	//Elem-Defx2
	 4,	//Mag-J
	 10,	//Elem-Atk-J
	 74,	//Auto-Potion
	 31,	//Recover
	 23,	//Item
	 20,	//Magic
	 21,	//GF
	 22, //Draw
	},
	{//Zéphyr
	 83,	//SumMag+10%
	 84,	//SumMag+20%
	 85,	//SumMag+30%
	 87,	//GFHP+10%
	 88,	//GFHP+20%
	 89,	//GFHP+30%
	 91,	//Boost
	 6,	//Spd-J
	 54,	//Spd+20%
	 55,	//Spd+40%
	 42,	//Str+20%
	 43,	//Str+40%
	 2,	//Str-J
	 12,	//Elem-Def-J
	 14,	//Elem-Defx2
	 10,	//Elem-Atk-J
	 63,	//Initiative
	 32,	//Absorb
	 23,	//Item
	 20,	//Magic
	 21,	//GF
	 22, //Draw
	},
	{//Cerberus
	 87,	//GFHP+10%
	 88,	//GFHP+20%
	 89,	//GFHP+30%
	 6,	//Spd-J
	 54,	//Spd+20%
	 55,	//Spd+40%
	 73,	//Auto-Haste
	 5,	//Spr-J
	 13,	//ST-Def-J
	 16,	//ST-Def-Jx2
	 17,	//ST-Def-Jx4
	 11,	//ST-Atk-J
	 18,	//Abilityx3
	 2,	//Str-J
	 78,	//Alert
	 4,	//Mag-J
	 75,	//Expendx2-1
	 8,	//Hit-J
	 23,	//Item
	 20,	//Magic
	 21,	//GF
	 22, //Draw
	},
	{//Alexander
	 87,	//GFHP+10%
	 88,	//GFHP+20%
	 89,	//GFHP+30%
	 83,	//SumMag+10%
	 84,	//SumMag+20%
	 85,	//SumMag+30%
	 91,	//Boost
	 59,	//MedData
	 114,//MedLVUp
	 51,	//Spr+20%
	 52,	//Spr+40%
	 113,//HighMag-RF
	 18,	//Abilityx3
	 10,	//Elem-Atk-J
	 14,	//Elem-Defx2
	 15,	//Elem-Defx4
	 5,	//Spr-J
	 33,	//Revive
	 23,	//Item
	 20,	//Magic
	 21,	//GF
	 22, //Draw
	},
	{//Helltrain
	 83,	//SumMag+10%
	 84,	//SumMag+20%
	 85,	//SumMag+30%
	 86,	//SumMag+40%
	 87,	//GFHP+10%
	 88,	//GFHP+20%
	 89,	//GFHP+30%
	 90,	//GFHP+40%
	 91,	//Boost
	 71,	//Auto-Shell
	 32,	//Absorb
	 30,	//Darkside
	 96,	//JunkShop
	 109,//ForbidMed-RF
	 15,	//Elem-Defx4
	 17,	//ST-Def-Jx4
	 23,	//Item
	 10,	//Elem-Atk-J
	 11,	//ST-Atk-J
	 20,	//Magic
	 21,	//GF
	 22, //Draw
	},
	{//Bahamut
	 83,	//SumMag+10%
	 84,	//SumMag+20%
	 85,	//SumMag+30%
	 86,	//SumMag+40%
	 87,	//GFHP+10%
	 88,	//GFHP+20%
	 89,	//GFHP+30%
	 90,	//GFHP+40%
	 91,	//Boost
	 58,	//Mug
	 75,	//Expendx2-1
	 70,	//Auto-Protect
	 23,	//Item
	 82,	//RareItem
	 64,	//Move-HPUp
	 44,	//Str+60%
	 50,	//Mag+60%
	 104,//ForbidMag-RF
	 19,	//Abilityx4
	 20,	//Magic
	 21,	//GF
	 22, //Draw
	},
	{//Pampa
	 87,	//GFHP+10%
	 88,	//GFHP+20%
	 89,	//GFHP+30%
	 23,	//Item
	 7,	//Eva-J
	 56,	//Eva+30%
	 75,	//Expendx2-1
	 9,	//Luck-J
	 57,	//Luck+50%
	 29,	//Defend
	 74,	//Auto-Potion
	 63,	//Initiative
	 65,	//HPBonus
	 66,	//StrBonus
	 67,	//VitBonus
	 68,	//MagBonus
	 69,	//SprBonus
	 64,	//Move-HPUp
	 36,	//Kamikaze
	 20,	//Magic
	 21,	//GF
	 22, //Draw
	},
	{//Tomberry
	 83,	//SumMag+10%
	 84,	//SumMag+20%
	 85,	//SumMag+30%
	 87,	//GFHP+10%
	 88,	//GFHP+20%
	 89,	//GFHP+30%
	 91,	//Boost
	 74,	//Auto-Potion
	 64,	//Move-HPUp
	 63,	//Initiative
	 57,	//Luck+50%
	 23,	//Item
	 56,	//Eva+30%
	 92,	//Haggle
	 93,	//Sell-High
	 94,	//Familiar
	 95,	//CallShop
	 34,	//LVDown
	 35,	//LVUp
	 20,	//Magic
	 21,	//GF
	 22, //Draw
	},
	{//orbital
	 83,	//SumMag+10%
	 84,	//SumMag+20%
	 85,	//SumMag+30%
	 86,	//SumMag+40%
	 87,	//GFHP+10%
	 88,	//GFHP+20%
	 89,	//GFHP+30%
	 90,	//GFHP+40%
	 91,	//Boost
	 111,//GFAblMed-RF
	 30,	//DarkSide
	 27,	//MadRush
	 8,	//Hit-J
	 6,	//Spd-J
	 7,	//Eva-J
	 57,	//Luck+50%
	 76,	//Expendx3-1
	 37,	//Devour
	 23,	//Item
	 20,	//Magic
	 21,	//GF
	 22, //Draw
	},
};

QString Data::getCardsLocation(int i)
{
	QString location;
	int locID = cardsLocation[i];
	if (locID==-1)		location = QObject::tr("Used Up");
	else if (locID==-2)	location = QObject::tr("Squall");
	else {
		location = _locations.at(locID);
		if (i>=200 && i<233)
			location.append(QObject::tr(" (card %1)").arg(_cards.at(77+(i-200))));
	}
	return location;
}

const int Data::cardsLocation[256] = {
	-1,250,0,0,0,0,0,0,0,0,111,111,111,125,111,116,114,
	125,128,132,132,132,129,129,129,149,0,0,220,219,74,69,69,
	65,65,71,70,80,80,70,135,135,69,67,0,67,0,147,170,
	0,64,64,64,64,85,83,86,86,87,87,87,195,190,194,192,
	193,193,190,195,96,93,96,93,93,93,101,104,105,101,101,101,
	101,101,101,129,205,205,205,183,138,138,141,139,143,142,138,138,
	147,150,153,150,201,201,202,202,202,197,199,197,197,164,44,165,
	44,44,160,44,44,44,44,156,148,0,0,0,0,0,0,0,
	0,70,70,69,70,69,70,69,65,74,80,0,0,0,0,0,
	0,0,0,0,0,81,192,194,138,87,0,0,0,0,0,107,
	101,101,102,101,97,94,93,93,95,0,0,0,0,0,0,0,
	0,0,0,227,44,0,0,0,0,0,0,0,0,44,44,44,
	44,44,44,44,44,44,44,250/*(200)GroChocobo...*/,103,73,70,227,149,207,0/*Ifrit*/,96,
	0/*Tauros*/,0/*Taurux*/,74,0/*Nosferatu*/,74,0/*Odin*/,86,0/*Cerbères*/,220,250,0/*Bahamut*/,250,0/*Orbital*/,164,250,225,
	190,80,250,88,127,183,74,163/*Squall(card)*/,0,0,0,0,0,0,0,-2,
	0,184,1,0,0,193,1,0,0,200,1,0,0,208,1
};

const cInt Data::momentLocation[403] = {
	cInt(0, -1),/*CD1*/ cInt(7, 71), cInt(12, 80), cInt(14, 66), cInt(16, 66), cInt(17, 66), cInt(19, 67), cInt(20, 92), cInt(21, 92), /*cInt(22, 89),*/ cInt(23, 92), cInt(24, 92), cInt(28, 92), cInt(30, 92), cInt(33, 65), cInt(34, 72),
	cInt(36, 70), cInt(38, 70), cInt(40, 90), cInt(45, 87), cInt(50, 91), cInt(55, 91), cInt(60, 91), cInt(65, 94), cInt(70, 93), cInt(75, 93), cInt(80, 93), cInt(81, 93), cInt(82, 93), cInt(83, 93), cInt(84, 93), cInt(92, 93),
	cInt(95, 100), cInt(100, 100), cInt(105, 100), cInt(110, 99), cInt(111, 99), cInt(115, 99), cInt(116, 99), cInt(117, 99), cInt(120, 99), cInt(122, 99), cInt(125, 99), cInt(135, 94), cInt(140, 70), cInt(142, 70), cInt(145, 74), cInt(150, 76),
	cInt(155, 76), cInt(170, 79), cInt(175, 78), cInt(177, 80), cInt(180, 73), cInt(195, 73), cInt(205, 65), cInt(216, 110), cInt(217, 110), cInt(218, 110), cInt(220, 110), cInt(222, 129), cInt(223, 130), cInt(224, 131), cInt(226, 131), cInt(228, 131),
	cInt(233, 130), cInt(235, 101), cInt(245, 103), cInt(255, 103), cInt(265, 103), cInt(270, 103), cInt(275, 101), cInt(280, 101), cInt(285, 102), cInt(290, 101), cInt(310, 182), cInt(315, 110), cInt(320, 111), cInt(321, 111), cInt(322, 115), cInt(323, 114),
	cInt(324, 113), cInt(328, 111), cInt(330, 111), cInt(333, 111), cInt(345, 111), cInt(348, 112), cInt(350, 129), cInt(351, 129), cInt(352, 129), cInt(353, 129), cInt(354, 127), cInt(356, 127), cInt(357, 127), cInt(358, 127), cInt(359, 129), cInt(360, 126),
	cInt(361, 126), cInt(362, 132), cInt(363, 126), cInt(364, 132), cInt(365, 127), cInt(366, 127), cInt(367, 129), cInt(368, 129), cInt(369, 132), cInt(370, 132), cInt(371, 132), cInt(372, 126), cInt(373, 132), cInt(374, 129), cInt(375, 129), cInt(376, 127),
	cInt(377, 126), cInt(379, 126), cInt(380, 126), cInt(381, 126), cInt(382, 127), cInt(383, 127), cInt(384, 127), cInt(385, 134), cInt(387, 126), cInt(388, 126), cInt(390, 132), cInt(392, 133), cInt(395, -2),/*CD2*/ cInt(420, 135), cInt(421, 135), cInt(423, 135),
	cInt(424, 135), cInt(426, 135), cInt(427, 135), cInt(429, 135), cInt(430, 135), cInt(433, 135), cInt(434, 135), cInt(436, 135), cInt(438, 135), cInt(440, 135), cInt(442, 135), cInt(445, 135), cInt(446, 135), cInt(450, 135), cInt(454, 136), cInt(455, 136),
	cInt(456, 137), cInt(457, 137), cInt(458, 137), cInt(459, 137), cInt(460, 137), cInt(461, 137), cInt(462, 137), cInt(463, 137), cInt(464, 137), cInt(465, 137), cInt(466, 137), cInt(467, 137), cInt(468, 137), cInt(469, 137), cInt(470, 137), cInt(471, 137),
	cInt(472, 137), cInt(473, 137), cInt(474, 137), cInt(475, 137), cInt(477, 137), cInt(478, 137), cInt(479, 137), cInt(480, 137), cInt(482, 137), cInt(483, 137), cInt(490, 65), cInt(494, 65), cInt(498, 65), cInt(502, 70), cInt(506, 70), cInt(510, 70),
	cInt(514, 69), cInt(518, 74), cInt(522, 74), cInt(525, 68), cInt(530, 68), cInt(531, 68), cInt(532, 68), cInt(533, 68), cInt(534, 68), cInt(536, 68), cInt(537, 68), cInt(538, 68), cInt(539, 68), cInt(540, 68), cInt(541, 68), cInt(542, 68),
	cInt(550, 68), cInt(552, 68), cInt(553, 68), cInt(554, 68), cInt(555, 74), cInt(556, 74), cInt(560, 74), cInt(563, 82), cInt(570, 74), cInt(571, 73), cInt(575, 70), cInt(600, 81), cInt(610, 81), cInt(612, 71), cInt(614, 70), cInt(615, 82),
	cInt(616, 82), cInt(618, 64), cInt(630, 183), cInt(632, 73), cInt(636, 70), cInt(637, 70), cInt(638, 74), cInt(639, 74), cInt(640, 82), cInt(641, 149), cInt(642, 149), cInt(643, 148), cInt(644, 149), cInt(645, 149), cInt(646, 146), cInt(647, 147),
	cInt(648, 147), cInt(650, 147), cInt(651, 147), cInt(655, 150), cInt(659, 77), cInt(670, 74), cInt(672, 74), cInt(690, 73), cInt(692, 149), cInt(693, 149), cInt(700, 149), cInt(710, 73), cInt(712, 80), cInt(720, 80), cInt(721, 146), cInt(722, 146),
	cInt(723, 151), cInt(740, 148), cInt(742, 183), cInt(743, 73), cInt(748, 74), cInt(750, 74), cInt(760, 84), cInt(765, 74), cInt(772, 183), cInt(774, 195), cInt(776, 183), cInt(778, 183), cInt(780, 183), cInt(782, 195), cInt(784, 183), cInt(786, 183),
	cInt(790, 195), cInt(800, 195), cInt(850, 74), cInt(852, 69), cInt(854, 77), cInt(856, 77), cInt(858, 74), cInt(860, 74), cInt(862, 77), cInt(864, 77), cInt(866, 77), cInt(868, 77), cInt(870, 77), cInt(872, 70), cInt(874, 65), cInt(876, 70),
	cInt(878, 70), cInt(880, 66), cInt(882, 66), cInt(884, 69), cInt(886, 74), cInt(888, 74), cInt(890, 69), cInt(892, 69), cInt(893, 124), cInt(894, 114), cInt(895, 120), cInt(900, 121), cInt(901, -3),/*CD3*/ cInt(910, 73), cInt(912, 71), cInt(1091, 185), cInt(1092, 185),
	cInt(1093, 186), cInt(1094, 186), cInt(1095, 186), cInt(1104, 186), cInt(1105, 74), cInt(1200, 71), cInt(1205, 204), cInt(1210, 204), cInt(1215, 204), cInt(1220, 204), cInt(1225, 204), cInt(1300, 204), cInt(1310, 183), cInt(1315, 71), cInt(1350, 71), cInt(1450, 207),
	cInt(1545, 74), cInt(1547, 71), cInt(1550, 69), cInt(1570, 82), cInt(1575, 82), cInt(1600, 155), cInt(1650, 156), cInt(1700, 157), cInt(1715, 157), cInt(1725, 157), cInt(1730, 157), cInt(1740, 158), cInt(1745, 158), cInt(1750, 158), cInt(1900, 169), cInt(2000, 164),
	cInt(2100, 170), cInt(2102, 170), cInt(2105, 171), cInt(2110, 172), cInt(2115, 172), cInt(2120, 172), cInt(2125, 172), cInt(2130, 170), cInt(2133, 171), cInt(2145, 170), cInt(2300, 168), cInt(2500, 160), cInt(2502, 173), cInt(2504, 222), cInt(2506, 223), cInt(2508, 220),
	cInt(2512, 220), cInt(2514, 223), cInt(2516, 223), cInt(2520, 223), cInt(2522, 223), cInt(2524, 223), cInt(2525, 223), cInt(2528, 223), cInt(2532, 223), cInt(2534, 219), cInt(2535, 223), cInt(2536, 223), cInt(2538, 224), cInt(2540, 224), cInt(2542, 224), cInt(2544, 222),
	cInt(2546, 223), cInt(2548, 226), cInt(2550, 219), cInt(2551, 219), cInt(2552, 219), cInt(2554, 221), cInt(2556, 221), cInt(2558, 221), cInt(2560, 221), cInt(2562, 226), cInt(2564, 221), cInt(3000, 213), cInt(3002, 213), cInt(3003, 213), cInt(3005, 213), cInt(3007, 210),
	cInt(3100, 208), cInt(3150, 180), cInt(3160, 209), cInt(3161, 209), cInt(3162, 209), cInt(3165, 209), cInt(3167, 208), cInt(3200, 173), cInt(3210, 173), cInt(3220, 173), cInt(3250, 173), cInt(3300, 173), cInt(3400, 208), cInt(3410, 208), cInt(3494, 188), cInt(3496, 188),
	cInt(3498, 188), cInt(3500, 188), cInt(3600, 183), cInt(3601, 166), cInt(3602, 166), cInt(3604, 166), cInt(3606, 166), cInt(3700, 209), cInt(3790, 209), cInt(3800, 208), cInt(3802, 181), cInt(3810, 181), cInt(3850, 181), cInt(3855, 181), cInt(3860, -4),/*CD4*/ cInt(4000, 249),
	cInt(4005, 228), cInt(4020, 248), cInt(4050, 229)
};

const int Data::drawPoints[256] =
{
	21, 4, 25, 27, 13, 12, 7, 21, 1, 41, 38, 50, 21, 6, 35, 24,
	30, 29, 33, 32, 21, 10, 8, 48, 27, 12, 2, 46, 9, 11, 5, 38,
	25, 44, 28, 23, 31, 29, 47, 22, 35, 30, 26, 25, 19, 9, 16, 23,
	4, 17, 18, 33, 45, 15, 37, 37, 24, 31, 43, 14, 41, 19, 39, 42,
	16, 23, 36, 23, 15, 14, 40, 39, 11, 44, 45, 9, 48, 32, 19, 6,
	3, 18, 14, 22, 24, 25, 28, 27, 34, 19, 49, 16, 35, 36, 23, 24,
	37, 26, 33, 34, 15, 23, 22, 50, 27, 36, 28, 37, 24, 15, 32, 14,
	16, 49, 19, 25, 34, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	21, 27, 7, 2, 8, 5, 4, 1, 21, 10, 22, 27, 50, 30, 35, 11,
	12, 24, 13, 29, 14, 9, 37, 3, 26, 6, 39, 15, 28, 36, 17, 23,
	18, 25, 31, 32, 17, 33, 42, 16, 19, 34, 39, 38, 17, 40, 41, 15,
	43, 44, 45, 46, 47, 48, 49, 48, 18, 17, 16, 14, 15, 32, 19, 34,
	24, 18, 17, 16, 14, 15, 32, 19, 34, 24, 18, 17, 16, 14, 15, 32,
	19, 34, 24, 19, 16, 14, 15, 32, 19, 34, 24, 16, 14, 34, 32, 19,
	34, 24, 16, 14, 15, 32, 19, 34, 24, 16, 34, 15, 32, 19, 34, 24,
	16, 14, 15, 32, 19, 4, 21, 28, 39, 16, 33, 33, 14, 15, 19, 50
};

const int Data::drawPointsLoc[256] =
{
	// field
	65, 78, 68, 64, 67, 81, 85, 87, 92, 93, 99, 101, 101/* and 182*/, 109, 113, 117,
	122, 125, 121, 124, 110, 110, 129, 134, 134, 134, -1, 135, 135, 136, 137, 137,
	137, 138, 138, 140, 138, 145, 145, 145, 154, 147, 146, 150, 149, 157, 157, 159,
	159, 160, 159, 167, -1, 167, 173, -1, 177, 177, 178, 182, 182, 182, 182, 181,
	181, 181, -1, 185, -1, -1, 182, 182, 189, 189, 189, 190, 191, 193, 197, 199,
	201, -1, 207, 210, 210, 211, 217, 217, 218, 218, 221, 225, -1, -1, -1, -1,
	-1, -1, -1, 228, 248, 237, 233, -1, -1, 243, 244, 245, 246, -1, 232, 236,
	231, 238, 240, 241, 245, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	// worldmap
	1, 1, 6, 8, 17, 15, 10, -1, 11, 14, 11, 20, 21, 15, 23, 15,
	15, 24, 62, 61, 57, 55, 53, 50, 26, 26, 30, 32, 32, 32, 37, 46,
	39, 39, 25, 13, 12, -1, 17, 41, 41, 41, 42, 41, 26, 26, 26, 32,
	31, 12, 11, 15, 21, 22, 15, 16, 51, 51, 51, 51, 51, 51, 51, 51,
	51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
	51, 51, 51, 51, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
	19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
	19, 19, 19, 19, 19, 1, 1, 15, 20, 43, 43, 43, 43, 47, 48, -1
};

const Point Data::wmLocation[21] =
{
	P(0, 0, 0, 0, Cities::Balamb),
	P(3680, 99, 412, 7, Cities::Dollet),
	P(21744, 113, 1176, 6, Cities::Timber),
	P(22576, 97, 898, 6, Cities::GGU),
	P(15488, 80, 2256, 8, Cities::Deling),
	P(4259, 258, 152, 64, Cities::Winhill),
	P(-897, -847, 49, 192, Cities::CentraRuins),
	P(-139, -882, 12, 0, Cities::Orphanage),
	P(-1244, -2127, 481, 232, Cities::TGU),
	P(-35, -5853, 5, 0, Cities::ShumiVillage),
	P(724, -869, 163, 128, Cities::SaltLake),
	P(12, 384, 22, 97, Cities::Esthar),
	P(10215, -8591, 64, 0, Cities::LunarGate),
	P(-241, -3315, 150, 0, Cities::ChocoboBeginner),
	P(147, -2467, 47, 0, Cities::ChocoboBasics),
	P(390, -3239, 81, 16, Cities::ChocoboRoaming),
	P(-63, -1764, 67, 0, Cities::ChocoboSanctuary),
	P(-181, -1594, 20, 0, Cities::ChocoboEnclosed),
	P(-708, -593, 52, 224, Cities::ChocoboFun),
	P(-200, -2292, 138, 0, Cities::ChocoboSolitude),
	P(210, -8585, 19, 0, Cities::RescuePod)
};

QStringList Data::maplist()
{
	QStringList maps;
	for (int i = 0; i < MAP_COUNT; ++i) {
		maps.append(_maplist[i]);
	}
	return maps;
}

const char *Data::_maplist[MAP_COUNT] = {
	"wm00",
	"wm01",
	"wm02",
	"wm03",
	"wm04",
	"wm05",
	"wm06",
	"wm07",
	"wm08",
	"wm09",
	"wm10",
	"wm11",
	"wm12",
	"wm13",
	"wm14",
	"wm15",
	"wm16",
	"wm17",
	"wm18",
	"wm19",
	"wm20",
	"wm21",
	"wm22",
	"wm23",
	"wm24",
	"wm25",
	"wm26",
	"wm27",
	"wm28",
	"wm29",
	"wm30",
	"wm31",
	"wm32",
	"wm33",
	"wm34",
	"wm35",
	"wm36",
	"wm37",
	"wm38",
	"wm39",
	"wm40",
	"wm41",
	"wm42",
	"wm43",
	"wm44",
	"wm45",
	"wm46",
	"wm47",
	"wm48",
	"wm49",
	"wm50",
	"wm51",
	"wm52",
	"wm53",
	"wm54",
	"wm55",
	"wm56",
	"wm57",
	"wm58",
	"wm59",
	"wm60",
	"wm61",
	"wm62",
	"wm63",
	"wm64",
	"wm65",
	"wm66",
	"wm67",
	"wm68",
	"wm69",
	"wm70",
	"wm71",
	"testno",
	"start",
	"start0",
	"gover",
	"ending",
	"test",
	"test1",
	"test2",
	"test3",
	"test4",
	"test5",
	"test6",
	"test7",
	"test8",
	"test9",
	"test13",
	"test14",
	"testbl0",
	"testbl1",
	"testbl2",
	"testbl3",
	"testbl4",
	"testbl5",
	"testbl6",
	"testbl7",
	"testbl8",
	"testbl9",
	"testbl13",
	"testbl14",
	"testmv",
	"bccent_1",
	"bccent1a",
	"bcform_1",
	"bcform1a",
	"bcgate_1",
	"bcgate1a",
	"bchtl_1",
	"bchtl1a",
	"bchtr_1",
	"bchtr1a",
	"bcmin1_1",
	"bcmin11a",
	"bcmin2_1",
	"bcmin21a",
	"bcmin2_2",
	"bcmin22a",
	"bcmin2_3",
	"bcmin23a",
	"bcport_1",
	"bcport1a",
	"bcport1b",
	"bcport_2",
	"bcport2a",
	"bcsaka_1",
	"bcsaka1a",
	"bcsta_1",
	"bcsta1a",
	"bdenter1",
	"bdifrit1",
	"bdin1",
	"bdin2",
	"bdin3",
	"bdin4",
	"bdin5",
	"bdview1",
	"bg2f_1",
	"bg2f_11",
	"bg2f_2",
	"bg2f_21",
	"bg2f_4",
	"bg2f_22",
	"bg2f_3",
	"bg2f_31",
	"bgbook_1",
	"bgbook1a",
	"bgbook1b",
	"bgbook_2",
	"bgbook2a",
	"bgbook_3",
	"bgbook3a",
	"bgbtl_1",
	"bgcrash1",
	"bgeat_1",
	"bgeat1a",
	"bgeat_2",
	"bgeat2a",
	"bgeat_3",
	"bggate_1",
	"bggate_2",
	"bggate_4",
	"bggate_5",
	"bggate_6",
	"bggate6a",
	"bghall_1",
	"bghall1a",
	"bghall1b",
	"bghall_2",
	"bghall2a",
	"bghall_3",
	"bghall3a",
	"bghall_4",
	"bghall4a",
	"bghall_5",
	"bghall_6",
	"bghall6b",
	"bghall_7",
	"bghall_8",
	"bghoke_1",
	"bghoke_2",
	"bghoke_3",
	"bgkote_1",
	"bgkote1a",
	"bgkote_2",
	"bgkote_3",
	"bgkote3a",
	"bgkote_4",
	"bgkote_5",
	"bgmast_1",
	"bgmast_2",
	"bgmast_3",
	"bgmast_4",
	"bgmast_5",
	"bgmd1_1",
	"bgmd1_2",
	"bgmd1_3",
	"bgmd1_4",
	"bgmd2_1",
	"bgmd2_3",
	"bgmd2_4",
	"bgmd2_5",
	"bgmd2_6",
	"bgmd2_7",
	"bgmd2_8",
	"bgmd3_1",
	"bgmd3_2",
	"bgmd4_1",
	"bgmd4_2",
	"bgmd4_3",
	"bgmdele1",
	"bgmdele2",
	"bgmdele3",
	"bgmdele4",
	"bgmon_1",
	"bgmon_2",
	"bgmon_3",
	"bgmon_4",
	"bgmon_5",
	"bgmon_6",
	"bgpark_1",
	"bgpaty_1",
	"bgpaty_2",
	"bgrank1",
	"bgroad_1",
	"bgroad_2",
	"bgroad_3",
	"bgroad_4",
	"bgroad_5",
	"bgroad_6",
	"bgroad_7",
	"bgroad_9",
	"bgroom_1",
	"bgroom_3",
	"bgroom_4",
	"bgroom_5",
	"bgroom_6",
	"bgryo1_1",
	"bgryo1_2",
	"bgryo1_3",
	"bgryo1_4",
	"bgryo1_5",
	"bgryo1_6",
	"bgryo1_7",
	"bgryo1_8",
	"bgryo2_1",
	"bgryo2_2",
	"bgsecr_1",
	"bgsecr_2",
	"bgsido_1",
	"bgsido1a",
	"bgsido_2",
	"bgsido_3",
	"bgsido_4",
	"bgsido_5",
	"bgsido5a",
	"bgsido_6",
	"bgsido_7",
	"bgsido_8",
	"bgsido_9",
	"bvboat_1",
	"bvboat_2",
	"bvcar_1",
	"bvtr_1",
	"bvtr_2",
	"bvtr_3",
	"bvtr_4",
	"bvtr_5",
	"cdfield1",
	"cdfield2",
	"cdfield3",
	"cdfield4",
	"cdfield5",
	"cdfield6",
	"cdfield7",
	"cdfield8",
	"crenter1",
	"crodin1",
	"cropen1",
	"crpower1",
	"crroof1",
	"crsanc1",
	"crsphi1",
	"crtower1",
	"crtower2",
	"crtower3",
	"crview1",
	"cwwood1",
	"cwwood2",
	"cwwood3",
	"cwwood4",
	"cwwood5",
	"cwwood6",
	"cwwood7",
	"ddruins1",
	"ddruins2",
	"ddruins3",
	"ddruins4",
	"ddruins5",
	"ddruins6",
	"ddsteam1",
	"ddtower1",
	"ddtower2",
	"ddtower3",
	"ddtower4",
	"ddtower5",
	"ddtower6",
	"doan1_1",
	"doan1_2",
	"doani1_1",
	"doani1_2",
	"doani3_1",
	"doani3_2",
	"doani4_1",
	"doani4_2",
	"dogate_1",
	"dogate1a",
	"dogate_2",
	"dohtl_1",
	"dohtr_1",
	"domin2_1",
	"domt1_1",
	"domt2_1",
	"domt3_1",
	"domt3_2",
	"domt3_3",
	"domt3_4",
	"domt4_1",
	"domt5_1",
	"domt6_1",
	"doopen_1",
	"doopen1a",
	"doopen_2",
	"doopen2a",
	"doport_1",
	"dopub_1",
	"dopub_2",
	"dopub_3",
	"dosea_1",
	"dosea_2",
	"dotown_1",
	"dotown1a",
	"dotown_2",
	"dotown2a",
	"dotown_3",
	"dotown3a",
	"eaplane1",
	"eapod1",
	"ebadele1",
	"ebadele2",
	"ebadele3",
	"ebadele5",
	"ebcont1",
	"ebcont2",
	"ebexit1",
	"ebexit2",
	"ebexit3",
	"ebexit4",
	"ebexit5",
	"ebexit6",
	"ebgate1",
	"ebgate1a",
	"ebgate2",
	"ebgate2a",
	"ebgate3",
	"ebgate3a",
	"ebgate4",
	"ebgate4a",
	"ebinhi1",
	"ebinhi1a",
	"ebinlow1",
	"ebinlow2",
	"ebinmid1",
	"ebinmid4",
	"ebinmid2",
	"ebinmid5",
	"ebinmid3",
	"ebinmid6",
	"ebinto1",
	"ebinto2",
	"ebinto3",
	"ebroad11",
	"ebroad12",
	"ebroad13",
	"ebroad21",
	"ebroad22",
	"ebroad23",
	"ebroad31",
	"ebroad32",
	"ebroad33",
	"ebroad41",
	"ebroad42",
	"ebroad43",
	"ebroad5",
	"ebroad6",
	"ebroad6a",
	"ebroad7",
	"ebroad7a",
	"ebroad8",
	"ebroad8a",
	"ebroad9",
	"ebroad9a",
	"eccway11",
	"eccway15",
	"eccway12",
	"eccway16",
	"eccway13",
	"eccway14",
	"eccway21",
	"eccway22",
	"eccway23",
	"eccway31",
	"eccway32",
	"eccway33",
	"eccway41",
	"eccway42",
	"eccway43",
	"ecenc1",
	"ecenc2",
	"ecenc3",
	"ecenter1",
	"ecenter4",
	"ecenter2",
	"ecenter5",
	"ecenter3",
	"eciway11",
	"eciway15",
	"eciway12",
	"eciway16",
	"eciway13",
	"eciway14",
	"ecmall1",
	"ecmall1a",
	"ecmall1b",
	"ecmview1",
	"ecmview2",
	"ecmview3",
	"ecmway1",
	"ecmway1a",
	"ecmway1b",
	"ecopen1",
	"ecopen1a",
	"ecopen1b",
	"ecopen2",
	"ecopen2a",
	"ecopen2b",
	"ecopen3",
	"ecopen3a",
	"ecopen3b",
	"ecopen4",
	"ecopen4a",
	"ecopen4b",
	"ecoway1",
	"ecoway1a",
	"ecoway1b",
	"ecoway2",
	"ecoway2a",
	"ecoway2b",
	"ecoway3",
	"ecoway3a",
	"ecoway3b",
	"ecpview1",
	"ecpview2",
	"ecpview3",
	"ecpway1",
	"ecpway1a",
	"ecpway1b",
	"ectake1",
	"ectake2",
	"ectake3",
	"edlabo1",
	"edlabo1a",
	"edlabo1b",
	"edmoor1",
	"edview1",
	"edview1a",
	"edview1b",
	"edview2",
	"eein1",
	"eein11",
	"eein12",
	"eein3",
	"eein31",
	"eein32",
	"eeview1",
	"eeview2",
	"eeview3",
	"efbig1",
	"efenter1",
	"efenter2",
	"efenter3",
	"efpod1",
	"efpod1a",
	"efpod1b",
	"efview1",
	"efview1a",
	"efview1b",
	"efview2",
	"ehback1",
	"ehback2",
	"ehblan1",
	"ehblan2",
	"ehblan3",
	"ehdrug1",
	"ehenter1",
	"ehenter2",
	"ehhana1",
	"ehnoki1",
	"ehroom1",
	"ehsea1",
	"ehsea2",
	"elroad1",
	"elroad2",
	"elroad3",
	"elstop1",
	"elview1",
	"elview2",
	"elwall1",
	"elwall2",
	"elwall3",
	"elwall4",
	"embind1",
	"embind1a",
	"embind2",
	"emlabo1",
	"emlabo1a",
	"emlabo1b",
	"emlabo2",
	"emlobby1",
	"emlobby3",
	"emlobby2",
	"emlobby4",
	"ephall1",
	"ephall2",
	"epmeet1",
	"eproad1",
	"eproad2",
	"epwork1",
	"epwork2",
	"epwork3",
	"escont1",
	"escouse1",
	"escouse2",
	"esform1",
	"esfreez1",
	"esview1",
	"esview2",
	"etsta1",
	"etsta2",
	"ewbrdg1",
	"ewdoor1",
	"ewele1",
	"ewele2",
	"ewele3",
	"ewpanel1",
	"ewpanel2",
	"fe2f1",
	"feart1f1",
	"feart1f2",
	"feart2f1",
	"febarac1",
	"febrdg1",
	"feclock1",
	"feclock2",
	"feclock3",
	"feclock4",
	"feclock5",
	"feclock6",
	"fegate1",
	"fehall1",
	"fehall2",
	"fein1",
	"fejail1",
	"felast1",
	"felfst1",
	"felrele1",
	"feopen1",
	"feopen2",
	"feout1",
	"fepic1",
	"fepic2",
	"fepic3",
	"ferfst1",
	"feroad1",
	"feroad2",
	"ferrst1",
	"feteras1",
	"fetre1",
	"feware1",
	"fewater1",
	"fewater2",
	"fewater3",
	"fewine1",
	"fewor1",
	"fewor2",
	"feyard1",
	"ffbrdg1",
	"ffhill1",
	"ffhole1",
	"ffseed1",
	"fhbrdg1",
	"fhdeck1",
	"fhdeck2",
	"fhdeck3",
	"fhdeck4",
	"fhdeck4a",
	"fhdeck5",
	"fhdeck6",
	"fhdeck7",
	"fhdeck7a",
	"fhedge1",
	"fhedge11",
	"fhedge2",
	"fhfish1",
	"fhform1",
	"fhhtl1",
	"fhhtr1",
	"fhmin1",
	"fhpanel1",
	"fhpara11",
	"fhpara12",
	"fhparar1",
	"fhparar2",
	"fhrail2",
	"fhrail3",
	"fhroof1",
	"fhtown1",
	"fhtown21",
	"fhtown22",
	"fhtown23",
	"fhview1",
	"fhwater1",
	"fhwise11",
	"fhwise12",
	"fhwise13",
	"fhwise15",
	"fhwisef1",
	"fhwisef2",
	"gdsand1",
	"gdsand2",
	"gdsand3",
	"gdsta1",
	"gdtrain1",
	"gfcar1",
	"gfcross1",
	"gfcross2",
	"gfelone1",
	"gfelone3",
	"gfelone2",
	"gfelone4",
	"gfhtl1",
	"gfhtl1a",
	"gfhtr1",
	"gfhtr1a",
	"gflain1",
	"gflain1a",
	"gflain11",
	"gflain2",
	"gflain2a",
	"gfmin1",
	"gfmin1a",
	"gfmin2",
	"gfmin2a",
	"gfrich1",
	"gfrich1a",
	"gfview1",
	"gfview1a",
	"gfvill1",
	"gfvill1a",
	"gfvill21",
	"gfvill24",
	"gfvill22",
	"gfvill23",
	"gfvill31",
	"gfvill32",
	"ggback1",
	"ggele1",
	"gggate1",
	"gggate2",
	"gggate3",
	"gggro1",
	"gggroen1",
	"gggroen2",
	"gggym1",
	"gggym2",
	"gghall1",
	"gghall2",
	"ggkodo1",
	"ggkodo2",
	"ggkodo4",
	"ggroad1",
	"ggroad2",
	"ggroad3",
	"ggroad5",
	"ggroad6",
	"ggroad7",
	"ggroad8",
	"ggroad8a",
	"ggroad8b",
	"ggroad9",
	"ggroad9a",
	"ggroad9b",
	"ggroom1",
	"ggroom2",
	"ggroom3",
	"ggroom4",
	"ggroom6",
	"ggroom7",
	"ggsta1",
	"ggstaen1",
	"ggstaen3",
	"ggstand1",
	"ggview1",
	"ggview2",
	"ggwitch1",
	"ggwitch2",
	"glclock1",
	"glclub1",
	"glclub3",
	"glclub4",
	"glform1",
	"glfurin1",
	"glfurin4",
	"glfurin5",
	"glfurin2",
	"glfurin3",
	"glfury1",
	"glfuryb1",
	"glgate1",
	"glgate2",
	"glgate2a",
	"glgate3",
	"glgate3a",
	"glgateb1",
	"glgatei1",
	"glgatei2",
	"glhtl1",
	"glhtr1",
	"glhtr1a",
	"glkara1",
	"glkara2",
	"glmall1",
	"glmall2",
	"glprefr1",
	"glprefr2",
	"glprefr3",
	"glprein1",
	"glpreo1",
	"glpreo2",
	"glpreo3",
	"glrent1",
	"glroad1",
	"glsta1",
	"glsta2",
	"glstage1",
	"glstage3",
	"glstaup1",
	"glstaup4",
	"glstaup2",
	"glstaup5",
	"glstaup3",
	"gltown1",
	"glwater1",
	"glwater2",
	"glwater3",
	"glwater4",
	"glwater5",
	"glwitch1",
	"glyagu1",
	"gmcont1",
	"gmcont2",
	"gmden1",
	"gmhouse1",
	"gmmoni1",
	"gmout1",
	"gmpark1",
	"gmpark2",
	"gmshoot1",
	"gmtika1",
	"gmtika2",
	"gmtika3",
	"gmtika4",
	"gmtika5",
	"gnroad1",
	"gnroad2",
	"gnroad3",
	"gnroad4",
	"gnroad5",
	"gnroom1",
	"gnroom2",
	"gnroom3",
	"gnroom4",
	"gnview1",
	"gparm1",
	"gpbig1",
	"gpbig1a",
	"gpbig2",
	"gpbig2a",
	"gpbig3",
	"gpbigin1",
	"gpbigin3",
	"gpbigin2",
	"gpbigin4",
	"gpbigin5",
	"gpcell1",
	"gpcont1",
	"gpcont2",
	"gpescap1",
	"gpexit1",
	"gpexit2",
	"gpgmn1",
	"gpgmn1a",
	"gpgmn2",
	"gpgmn3",
	"gppark1",
	"gproof1",
	"gproof2",
	"gwbrook1",
	"gwenter1",
	"gwgrass1",
	"gwpool1",
	"gwpool2",
	"gwroad1",
	"rgair1",
	"rgair2",
	"rgair3",
	"rgcock1",
	"rgcock2",
	"rgcock3",
	"rgexit1",
	"rgexit2",
	"rgguest1",
	"rgguest2",
	"rgguest3",
	"rgguest4",
	"rgguest5",
	"rghang1",
	"rghang11",
	"rghang2",
	"rghatch1",
	"rgroad1",
	"rgroad11",
	"rgroad2",
	"rgroad21",
	"rgroad3",
	"rgroad31",
	"sdcore1",
	"sdcore2",
	"sdisle1",
	"seback1",
	"seback2",
	"secont1",
	"secont2",
	"sefront1",
	"sefront2",
	"sefront3",
	"sefront4",
	"seroom1",
	"seroom2",
	"ssadel1",
	"ssadel2",
	"ssblock1",
	"sscont1",
	"sscont2",
	"ssdock1",
	"sselone1",
	"sslock1",
	"ssmedi1",
	"ssmedi2",
	"sspack1",
	"sspod1",
	"sspod2",
	"sspod3",
	"ssroad1",
	"ssroad2",
	"ssroad3",
	"ssspace1",
	"ssspace2",
	"ssspace3",
	"tgcourt1",
	"tgcourt5",
	"tgcourt2",
	"tgcourt3",
	"tgcourt4",
	"tgfront1",
	"tggara1",
	"tggate1",
	"tggrave1",
	"tgroom1",
	"tgroom2",
	"tgstage1",
	"tgview1",
	"tiagit1",
	"tiagit2",
	"tiagit3",
	"tiagit4",
	"tiagit5",
	"tiback1",
	"tiback2",
	"tigate1",
	"tihtl1",
	"tihtr1",
	"tilink1",
	"tilink2",
	"timania1",
	"timania2",
	"timania3",
	"timania4",
	"timania5",
	"timin1",
	"timin21",
	"timin22",
	"tipub1",
	"tistud1",
	"tistud21",
	"tistud22",
	"titown1",
	"titown2",
	"titown3",
	"titown4",
	"titown51",
	"titown52",
	"titown6",
	"titown7",
	"titown8",
	"titrain1",
	"titv1",
	"titvout1",
	"tivisi1",
	"tivisi2",
	"tiyane1",
	"tiyane2",
	"tiyane3",
	"tmdome1",
	"tmdome2",
	"tmelder1",
	"tmele1",
	"tmgate1",
	"tmhtl1",
	"tmhtr1",
	"tmkobo1",
	"tmkobo2",
	"tmmin1",
	"tmmura1",
	"tmmura2",
	"tmsand1",
	"tvglen1",
	"tvglen2",
	"tvglen3",
	"tvglen4",
	"tvglen5",
	"laguna01",
	"laguna02",
	"laguna03",
	"laguna04",
	"laguna05",
	"laguna06",
	"laguna07",
	"laguna08",
	"laguna09",
	"laguna10",
	"laguna11",
	"laguna12",
	"laguna13",
	"laguna14",
	"gpbigin6",
	"fhtown24",
	"rgcock4",
	"rgcock5",
	"ffhole1a",
	"ehblan1a",
	"ehenter3",
	"ehroom1a",
	"eproad1a",
	"fewhite1",
	"feblack1",
	"glwitch3",
	"ehback1a",
	"ehblan1b",
	"ehenter4",
	"ehroom1b",
	"ehsea1a"
};
