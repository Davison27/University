import {ScrollView} from 'react-native';

import {useEffect, useState} from 'react';
import Loading from '../../layout/Loading';
import {
  BackgroundImage,
  Filter,
  Lore,
  Name,
  Passive,
  PassiveDescription,
  PassiveInfo,
  PassiveImage,
  PassiveName,
  PassiveSection,
  PassiveTitle,
  Skin,
  SkinImage,
  SkinName,
  SkinsSection,
  SkinsTitle,
  Spell,
  SpellCost,
  SpellCooldown,
  SpellDescription,
  SpellInfo,
  SpellImage,
  SpellName,
  SpellsSection,
  SpellsTitle,
  Tag,
  TagsSection,
  Title,
  TitleSection,
  Wrapper,
} from './Champion_styles';
import {SpellProps, SkinsProps} from './types';

const Champion = ({route}) => {
  const passiveImageUrl =
    'http://ddragon.leagueoflegends.com/cdn/12.23.1/img/passive';
  const skinImageUrl =
    'http://ddragon.leagueoflegends.com/cdn/img/champion/loading';
  const spellImageUrl =
    'https://ddragon.leagueoflegends.com/cdn/12.23.1/img/spell';
  const {championName} = route.params;
  const [image, setImage] = useState<string>();
  const [isLoading, setIsLoading] = useState(true);
  const [lore, setLore] = useState();
  const [name, setName] = useState();

  const [passiveSpell, setPassiveSpell] = useState();
  const [skins, setSkins] = useState<SkinsProps[]>();
  const [spells, setSpells] = useState<SpellProps[]>();
  const [tags, setTags] = useState<string[]>();
  const [title, setTitle] = useState();
  const [version, setVersion] = useState('12.23.1');

  useEffect(() => {
    (async () => {
      const championResponse = await fetch(
        `http://ddragon.leagueoflegends.com/cdn/${version}/data/en_US/champion/${championName}.json`,
      );
      const championResult = await championResponse.json();

      setLore(championResult.data[championName].lore);
      setName(championResult.data[championName].name.toUpperCase());
      setPassiveSpell(championResult.data[championName].passive);
      setSkins(
        championResult.data[championName].skins.map(skin => {
          return {
            num: skin.num,
            name: skin.name,
            chromas: skin.chromas,
          };
        }),
      );
      setSpells(
        championResult.data[championName].spells.map(spell => {
          return {
            description: spell.description,
            id: spell.id,
            name: spell.name,
            cooldown: spell.cooldown.join('/'),
            cost: spell.cost.join('/'),
          };
        }),
      );
      setTags(championResult.data[championName].tags);
      setTitle(championResult.data[championName].title);

      const imageResponse = await fetch(
        `http://ddragon.leagueoflegends.com/cdn/img/champion/loading/${championName}_0.jpg`,
      );
      setImage(imageResponse.url);

      setIsLoading(false);
    })();
  }, []);

  return (
    <>
      {!isLoading ? (
        <>
          <BackgroundImage source={{uri: image}} />
          <Filter />
          <ScrollView>
            <Wrapper>
              <TitleSection>
                <Name>{name}</Name>
                <Title>{title}</Title>
              </TitleSection>
              <Lore>{lore}</Lore>
              <TagsSection>
                {tags?.map(tag => (
                  <Tag key={tag}>{tag}</Tag>
                ))}
              </TagsSection>
              <PassiveTitle>Passive</PassiveTitle>
              <PassiveSection>
                <Passive>
                  <PassiveImage
                    source={{
                      uri: `${passiveImageUrl}/${passiveSpell.image.full}`,
                    }}></PassiveImage>
                  <PassiveInfo>
                    <PassiveName>{passiveSpell.name}</PassiveName>
                    <PassiveDescription>
                      {passiveSpell.description}
                    </PassiveDescription>
                  </PassiveInfo>
                </Passive>
              </PassiveSection>
              <SpellsTitle>Abilities</SpellsTitle>
              <SpellsSection>
                {spells?.map(spell => (
                  <Spell key={spell.id}>
                    <SpellImage
                      source={{
                        uri: `${spellImageUrl}/${spell.id}.png`,
                      }}></SpellImage>
                    <SpellInfo>
                      <SpellName>{spell.name}</SpellName>
                      <SpellDescription>{spell.description}</SpellDescription>
                      <SpellCooldown>
                        Cooldown: {spell.cooldown} seconds
                      </SpellCooldown>
                      <SpellCost>Cost: {spell.cost} mana</SpellCost>
                    </SpellInfo>
                  </Spell>
                ))}
              </SpellsSection>
              <SkinsTitle>Skins</SkinsTitle>
              <SkinsSection>
                {skins?.map(skin => (
                  <Skin key={skin.num}>
                    <SkinImage
                      source={{
                        uri: `${skinImageUrl}/${championName}_${skin.num}.jpg`,
                      }}></SkinImage>
                    <SkinName>{skin.name}</SkinName>
                  </Skin>
                ))}
              </SkinsSection>
            </Wrapper>
          </ScrollView>
        </>
      ) : (
        <Loading />
      )}
    </>
  );
};

export default Champion;
