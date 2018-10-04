// import React
import React from 'react'
// import { render } from 'react-dom'
import { render } from 'react-dom'
// import Menu
import Menu from './components/Menu'
// import data from '../data/recipes'
import data from '../data/recipes'
// the app
window.React = React

render(<Menu recipes={data} />, document.getElementById('react-container'))
