import React from 'react';
import {
  BackgroundVideo,
  ImageWrapper,
  LOLImage,
  MainView,
  SearchBarStyle,
  TitleText,
  Wrapper,
} from './HomeScreen_styles';
import {useHomeScreen} from './hooks';

const HomeScreen = ({navigation}: any) => {
  const {handleChange, handleSearchPress} = useHomeScreen(navigation);
  return (
    <MainView>
      <BackgroundVideo
        source={require('../../../assets/lol.mp4')}
        repeat={true}
        muted={false}
        resizeMode={'cover'}
      />

      <Wrapper>
        <ImageWrapper>
          <LOLImage source={require('../../../assets/ucoGG.png')} />
        </ImageWrapper>
        <TitleText>¡Welcome to ucoGG!</TitleText>
        {/* <Searchbar
          value="Kan0#EUW"
          icon={require('../../assets/search.png')}></Searchbar> */}
        <SearchBarStyle
          placeholder="Champion name"
          onChangeText={handleChange}
          onSearchPress={handleSearchPress}

          // onSubmitEditing={handleSubmit}
        />
      </Wrapper>
    </MainView>
  );
};

export default HomeScreen;
