import React from 'react';
import ReactDOM from 'react-dom';
import App from './App';
import './index.css';
import { render } from 'react-dom'
import { Router, Route, hashHistory } from 'react-router'

window.React = React

render((
  <Router history={hashHistory}>
    <Route path="/" component={App}>
       <Route path="/:location" component={App} />
    </Route>
  </Router>
), document.getElementById('root'))

//ReactDOM.render(
//  <App />,
//  document.getElementById('root')
//);
