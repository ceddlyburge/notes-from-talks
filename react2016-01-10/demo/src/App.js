import React from 'react';
import Header from './components/header';
import List from './components/list';

const App = (props) => (
  <div>
    <Header name={props.name} />
    <List />
  </div>
)

export default App;