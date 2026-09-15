### Generic Abilities
In general, most bits of information will be considered "abilities." For example, a rogue's evasion is considered an ability. However, so too is the more complex example of a Monk's ki points and martial arts, respectively. Beyond even that, ability score increases will be also considered a generic 'ability.' This allows for easy extensibility, as each class needs to simply specify a set of abilities that they intend to provide to the player, and the specific subtypes of ability they are. See Abilities.md

### Current issues
- Bard's jack of all trades
- expertise
- is the monk ki's save DC going to be an issue? time shall tell
	- this is a relatively common thing in a few places, generally subclasses. see: barbarian:storm herald|wild magic|beast|berserker|giant
- is the fact that selection lists create infinite loops a problem? who knows lol
- concern: list sizes dynamically, do we worry about how (for example) bards can pull "magical secrets" from any spell list, BUT of spells they can cast, eg dependent on level?
### Classes
- Name of class
- Hit dice
- Starting proficiency bonuses, items
	- the proficiency bonuses potentially will be an ability, as they select from a list
- requisite stats to multiclass into the class
- Spellcasting information
	- associated stat
	- calculate attack bonus
	- calculate spell save DC
	- how their preparation/known spells work
	- their spell list -- link to an external list
	- focus/components
	- spell slots
- Level that they select subclass
	- and the subclass JSON files linked
- Rest of abilities

### Subclasses
- subclass name
- spellcasting
	- sometimes expand spell list
	- sometimes always know these spells
	- sometimes always prepare these spells
	- this is levelled
	- sometimes it doesn't exist at all lol
- list of abilities

### Items
- they should have equip/dequip events?
- text obviously
- set of abilities (ability score increase, attack)
- see abilities

### Race
- name
- ability score increasess
- note: won't include stuff light height, age, alignment etc, speed hardcoded. Information should still be encoded but not enforced
- abilities
	- draconic ancestry
	- proficiency
```json
{
	"Name": "title -- entire thing, eg High Elf",
	"Ability lists": ["Generic abilties.json"],
	"Abilities": [
		/*01*/["Mighty guardian", "other ability", "tough",...],
		/*02*/[""],
		/*03*/[],
		/*04*/["Ability Score Improvement"]
		...
		[]
	],
	"Speed": "30ft",
	"Description": "flavor flavor flavor"
}
```

### Custom markdown
#### Goal
the goal here is to make a markdown for specific rendering in the gui, so we can make it dynamic and good.
#### Needs
- need to specify what stats is pulled
	- martial arts die
	- proficiency scores/bonus
	- number of uses remaining? mayyyybbbeeeeeee
	- more complex topics, eg custom formulas ("An unwilling creature must succeed on a Strength saving throw (DC equals 8 + your proficiency bonus + your Strength modifier) to avoid the effect.")
- need to be able to specify a table existence
	- for example, wild magic
	- not sure when the rendering should happen, but it should exist
