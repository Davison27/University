import {LoadingVideo} from './styles';

const Loading = () => {
  return (
    <LoadingVideo
      source={require('../../../assets/poroLoading.mp4')}
      repeat={true}
      muted={true}
      resizeMode={'cover'}
    />
  );
};

export default Loading;
