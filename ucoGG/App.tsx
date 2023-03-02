import * as React from 'react';
import HomeScreen from './src/components/pages/Homescreen/HomeScreen';
import Champion from './src/components/pages/Champion/Champion';
import ItemSearch from './src/components/pages/ItemSearch/ItemSearch';
import {NavigationContainer} from '@react-navigation/native';
import {createNativeStackNavigator} from '@react-navigation/native-stack';
import {createBottomTabNavigator} from '@react-navigation/bottom-tabs';
import {WebView} from 'react-native-webview';
import Ionicons from 'react-native-vector-icons/Ionicons';
import Item from './src/components/pages/Item/Item';

const Stack = createNativeStackNavigator();
const Tab = createBottomTabNavigator();

function ItemStackScreen() {
  return (
    <Stack.Navigator>
      <Stack.Screen
        name="ItemSearch"
        component={ItemSearch}
        options={{headerShown: false}}
      />
      <Stack.Screen
        name="ItemScreen"
        component={Item}
        options={{headerShown: false}}
      />
    </Stack.Navigator>
  );
}

function HomeStackScreen() {
  return (
    <Stack.Navigator>
      <Stack.Screen
        name="HomeScreen"
        component={HomeScreen}
        options={{headerShown: false}}
      />
      <Stack.Screen
        name="Champion"
        component={Champion}
        options={{headerShown: false}}
      />
    </Stack.Navigator>
  );
}

function MapStackScreen() {
  return <WebView source={{uri: `https://map.leagueoflegends.com/en_US`}} />;
}

const App = () => {
  return (
    <NavigationContainer>
      <Tab.Navigator
        screenOptions={{
          tabBarActiveBackgroundColor: '#13181B',
          tabBarHideOnKeyboard: true,
          tabBarInactiveBackgroundColor: '#13181B',
        }}>
        <Tab.Screen
          name="Home"
          component={HomeStackScreen}
          options={{
            headerShown: false,
            tabBarIcon: ({color, size, focused}) => (
              <Ionicons name="ios-home" size={size} color={color} />
            ),
          }}
        />
        <Tab.Screen
          name="Items"
          component={ItemStackScreen}
          options={{
            headerShown: false,
            tabBarIcon: ({color, size, focused}) => (
              <Ionicons name="apps" size={size} color={color} />
            ),
          }}
        />
        <Tab.Screen
          name="Map"
          component={MapStackScreen}
          options={{
            headerShown: false,
            tabBarIcon: ({color, size}) => (
              <Ionicons name="ios-map" size={size} color={color} />
            ),
          }}
        />
      </Tab.Navigator>
    </NavigationContainer>
  );
};

export default App;
