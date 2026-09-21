#### Ability Types (speculative)
- Generics
	- shit like wildshape, like monk's fisticuffs, like the bards' mote, that are things that the player very much *can* do, but don't require much processing beyond generics
- List selection
	- eg mystic arcanum, you select an item from a list on some events
	- feats also count for this. Should specify prereqs.
	- has event hooks, so you need to name events that happen. Eg some could activate on short rest, others could activate on level-up
	- functionally this is selecting from **abilities**, no more, no less. Though some of them could be secretly families of abilities. This warrants further investigation.
- List replacement
	- similar to list selection, however this is for replacement. For example, replacing a cantrip or that weird gith thing with proficiencies
- Stat modifications
	- additional movement speed, additional stats
	- this includes expertise. These are so limited we might be able to go direct on them, eg list out all types
	- AC should not be included here. Too complicated
#### Generic abilities
- name -- note: some abilities can have the same name (extra attack, ability score improvement), so make sure to note where they came from somewhere
- level acquired
- Text
	- sometimes have a table in the text, custom markdown, eg druid wildshape table?
- associated values
	- What is it (die or strict value)
	- Number of uses
	- Recharge on \[what\]
- scaling -- not strictly a part of the fields, but part of json custom markdown
- is optional -- sometimes a feature is completely optional in events like long rests or level ups.
- requirements
	- for items such as feats. this should be listed as full optional, and able to be overridden
- level up events
	- some abilities add more abilities, eg artificier:armorer's armor model has you choose what type of armor you make. Each one of those are an individual ability. AND on 15th level they add another ability each.
	- some abilities just have stuff (see ability types)
- tags -- list of associated tags, for example:
	- action
	- bonus action
	- movement
	- healing
	- hidden -- this one is important, for example the player doesn't wanna see ability score increase in their abilities list fuckin' constantly
- child abilities

```json
{
  "type": "generic", //cuz differentiating
  "name": "generic title",
  "text": "waow text section",
  "prerequisites": "This section is purely cosmetic",
  "optional": false, //some abilities are optional. Some aren't
  "hidden": false, //kept out of tags bc used a lot
  "scaler": {
    "name": "Martial Arts die",
    "scaling": [[1, "1d4"], [5, "1d6"], [11, "1d8"], [17, "1d10"]]
    //greater than lv 1, you get 1d4, but at >= 5 you get 1d6, etc etc
  },
  "charges": { //this is for thinks like wildshape, which have a certain amount of charges
    "count": 10,
    //long/short rest are going to be keywords, other is just a generic text discription
    //similarly, inft is just when it's all recharged on the event
    "recharge type": ["long rest/short rest/other", "all/dice/number"],
    "recharge val": "inft/4d8+1/2",
  },
  "tags": ["attack", "action", "melee", "monk"],
  "sub_abilities": [...], // list of the same type or filepaths 
  "origin": "someplace"
}
```


#### List selection
```json
{
	"type": "list select",
	"name": "list title",
	"text": "texty text text",
	"prerequisites": "cosmetics",
	//as before short and long rest are protected names
	"optional": false,
	"hidden": false, //this could still be relevent, why not y'know?
	
	"hooks": ["short rest", "long rest", "other1", "other 2"],
	"count type": "number/stat", //stat should be just about any field
	"count": "[number]/[stat identifier]",
	"internal list": true,
	"spells": false, //if spells it should be read differently, spells are not strictly abilities
	"list path": "", //should be omitted or left blank, if internal list is false it leads somewhere
	"list": ["ability 1.json", "ability 2.json", "ability 3.json"]
}
```

#### List replacement
```json
{
	"type": "list replace",
	"name": "replacement ability title",
	"text": "texty text text",
	"prerequisites": "cosmetics",
	"optional": true, //99% sure this should always be the case but :shrug:
	"hidden": false,
	"hooks": ["short rest", "level up", "dawn"],
	
	"count type": "number/stat", //stat should be just about any field
	"count": "[number]/[stat identifier]",
	"spells": false,
	"list path": "", //should be omitted or left blank, if internal list is false it leads somewhere
	"list": ["ability 1.json", "ability 2.json", "ability 3.json"],
	"ability": "name of ability to replace" //putting the work on the programmer's end lol
}
```

### Override
```json
{
	"type": "override",
	"name": "archdruid",
	"target": "wild shape",
	"new": {
		/*new ability here*/
	}
}
```

#### Trait modification
```json
{
	"type": "ability mod",
	"name": "ability score increase",
	"text": "moar text",
	"preqrequisites": "this is cosmetic",
	"type": "const/count/identifier/formula",
	"stat": ["identifier 1", "identifier 2"], //the output
	"const val": 8,
	"count": [[1, 2], [5, 3], [9, 19]], //behaves the same as generics
	"identifier": "identifier", //only one source
	"formula": "[identifier 1]*[identifier 2]+[5]" //this will suck. not 100% sure how it should work.
	//also it should double check somehow to not go over like 20 str for example
}
```

#### Spell list modification
```json
{
	"type": "spell list mod",
	"name": "name plz",
	"text": "description",
	"spell list": ["spell1.json", "spell2.json"]
}
```

### Class basic concept
```json
{
	"class": "name",
	"ability table": ["druid_abilities.json", "generic_abilities.json"], 
	"abilities": [
		/*01*/["Mighty guardian.json", "other ability.json", "tough",...],
		/*02*/[""],
		/*03*/[],
		/*04*/["Ability Score Improvement"]
		...
		[]
	],
	"subclass": {
		"level": n,
		"options": ["sub1.json", "sub2.json"]
	},
	"hit die": "1DN",
	//proficiencies are adding to a list, so lv 1 ability
	"spellcasting": {
		"focus": "text describing",
		"spell list": "spell_list.json",
		"ritual": true,
		"ability": "[Charisma id/Wisdon id]", //save check is 8+prof+ability; attack roll is prof+ability
		"Preparing type": "[formula/constant/reference/table]",
		"Prepared value": "smthn as above",
		"Known type": "[formula/constant/reference/table]",
		"Known value": "smthn as above",
		"Prepared/known flavor text": "text",
		"spell slots": [
			[2, 1, 0, ...], //0th is cantrips
			[2, 2, 1, ...],
			...
		]
	}
}
```


```json
//druid_abilities.json
{
	"Drudic" : {},
	"Druidic Spellcasting": {},
	"Wild Shape": {},
	"Druid Circle": {},
	"Wild companion": {},
	"Druid Cantrip Versilitility": {},
	"Timeless Body": {},
	"Archdruid": {}
}
```

```json
//subclass
{
	"name": "subclass name",
	"description": "descript please",
	"ability table": ["this_subclass_abilities.json", "generic_abilities.json"], 
	"abilities": [
		/*01*/["Mighty guardian.json", "other ability.json", "tough",...],
		/*02*/[""],
		/*03*/[],
		/*04*/["Ability Score Improvement"]
		...
		[]
	],
	"spellcasting": { //if this field is empty then it doesn't do it
		//just use format from class
	},
}
```

```json
//item hypothetical
{
	"torch": {
		"description": "text",
		"abilities": ["ability.json", ...]
	}
}
```

```json
{
	"name": "text",
	"description": "texttexttexttextetxtextetxetxtsadtf",
	"age": "text",
	"alignment": "text",
	"size": "text",
	"abilities": ["ability.json", ...], // stuff such as speed, languages, skills, spells, ability score increase, etc..
	"spellcasting": {
		// see "class basic concept"
	}
}
```
