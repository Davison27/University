import {Image, Text, View} from 'react-native';
import styled from 'styled-components';
import Video from 'react-native-video';
import SearchBar from 'react-native-dynamic-search-bar';

export const MainView = styled(View)`
  height: 100%;
`;

export const BackgroundVideo = styled(Video)`
  position: absolute;
  top: 0;
  left: 0;
  bottom: 0;
  right: 0;
`;

export const ImageWrapper = styled(View)`
  width: 148px;
  height: 200px;
`

export const LOLImage = styled(Image)`
  width: 100%;
  height: 100%;
  object-fit: contain;
`;

export const TitleText = styled(Text)`
  color: white;
  margin-top: 5px;
  font-family: "BeaufortforLOL-Bold";
  font-size: 35px;
  font-weight: 600;
`;

export const Wrapper = styled(View)`
  align-items: center;
  display: flex;
  flex-direction: column;
  height: 80%;
  justify-content: center;
  padding: 10px;
`;

export const SearchBarStyle = styled(SearchBar)`
  margin-top: 3%;
`;
