/**
 * @format
 */

import 'react-native';
import React from 'react';
import App from '../App';

// Note: test renderer must be required after react-native.
import renderer from 'react-test-renderer';
import Item from '../src/components/pages/Item/Item';
import HomeScreen from '../src/components/pages/Homescreen/HomeScreen';

it('Item renders correctly', () => {
  renderer.create(<Item />);
});

it('App renders correctly', () => {
  renderer.create(<App />);
});

it('Homescreen renders correctly', () => {
  renderer.create(<HomeScreen />);
});
