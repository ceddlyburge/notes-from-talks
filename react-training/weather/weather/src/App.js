import React, { Component } from 'react';
import logo from './logo.svg';
import './App.css';
import Weather from './components/Weather'
import ChooseLocation from './components/ChooseLocation'
import { Router, Route, Link } from 'react-router'

class App extends Component {
    constructor(){
        super()
        this.state = { location: "", description: "" }
    }
    componentWillReceiveProps(){
        this.loadWeather(this)
    }
    componentDidMount(){
        this.loadWeather(this)
    }
    loadWeather(self) {
        let url = `http://api.openweathermap.org/data/2.5/weather?q=${this.props.params.location}&APPID=48f2d5e18b0d2bc50519b58cce6409f1`
        $.ajax({
            url: url,
            dataType: 'json',
            cache: false,
            success: function(data) {
                self.setState({location: data.name, description:data.weather[0].description })
            }.bind(self),
            error: function(xhr, status, err) {
                console.error(self.props.url, status, err.toString())
            }.bind(self)
        });
    }
    locationChange(e){
        this.props.history.push('/' + e.target.value);
        //this.setState({inputLocation: e.target.value})
        //this.loadWeather(this)
    }
  render() {
    return (
      <div className="App">
        <div className="App-header">
          <h2>Weather</h2>
        </div>
        <ChooseLocation location={this.props.params.location} locationChange={this.locationChange.bind(this)} />
        <Weather location={this.state.location} description={this.state.description} />
      </div>
    );
  }
}

export default App;
