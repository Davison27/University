import React from 'react';
import {
  BackgroundImage,
  ImageWrapper,
  ORNImage,
  MainView,
  SearchBarStyle,
  TitleText,
  Wrapper,
} from './ItemSearch_styles';
import {useItemSearch} from './hooks';

const ItemSearch = ({navigation}: any) => {
  const {handleChange, handleSearchPress} = useItemSearch(navigation);

  return (
    <MainView>
      <BackgroundImage source={require('../../../assets/item.jpg')} />
      <Wrapper>
        <ImageWrapper>
          <ORNImage source={require('../../../assets/ornn.png')} />
        </ImageWrapper>
        <TitleText>Items</TitleText>
        {/* <Searchbar
          value="Kan0#EUW"
          icon={require('../../assets/search.png')}></Searchbar> */}
        <SearchBarStyle
          placeholder="Item name"
          onChangeText={handleChange}
          onSearchPress={handleSearchPress}

          // onSubmitEditing={handleSubmit}
        />
      </Wrapper>
    </MainView>
  );
};

export default ItemSearch;
