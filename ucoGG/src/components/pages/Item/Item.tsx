import {ScrollView, Text} from 'react-native';
import {useEffect, useState} from 'react';
import Loading from '../../layout/Loading';
import lolItems from 'lol-items/items';
import {ItemProps} from './types';
import {
  BackgroundImage,
  Description,
  ItemImage,
  Name,
  Price,
  PriceSection,
  PriceTitle,
  Tag,
  TagsSection,
  Wrapper,
} from './Item_styles';

const Item = ({route}: any) => {
  const {itemName} = route.params;
  const [isLoading, setIsLoading] = useState(true);
  const [items, setItems] = useState<ItemProps[]>(lolItems);
  const [item, setItem] = useState<ItemProps>();
  const [itemImage, setItemImage] = useState<string>();

  useEffect(() => {
    const currentItem = items.find(item => item.name === itemName);
    setItem(currentItem);
    setIsLoading(false);
  }, []);

  return (
    <>
      {!isLoading ? (
        <>
          <BackgroundImage source={require('../../../assets/item.jpg')} />

          <Wrapper>
            <ItemImage
              source={{
                uri: item?.icon,
              }}></ItemImage>
            <Name>{item?.name}</Name>
            <Description>{item?.plaintext}</Description>
            <TagsSection>
              {item?.tags.map(tag => (
                <Tag key={tag}>{tag}</Tag>
              ))}
            </TagsSection>
            <PriceSection>
              <PriceTitle>Prices</PriceTitle>
              <Price>
                Base {'---->'} {item?.price.base} gold
              </Price>
              <Price>
                Sell {'---->'} {item?.price.sell} gold
              </Price>
              <Price>
                Total {'---->'} {item?.price.total} gold
              </Price>
            </PriceSection>
          </Wrapper>
        </>
      ) : (
        <Loading />
      )}
    </>
  );
};

export default Item;
