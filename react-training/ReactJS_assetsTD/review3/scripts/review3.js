let PhotoBox = React.createClass({
  loadPhotosFromServer: function() {
      let localUrl = `${this.props.url}?q=${this.props.city},${this.props.country}${this.props.ApiKey}`
    $.ajax({
      url: localUrl,
      dataType: 'json',
      cache: false,
      success: function(data) {
        this.setState({data: data})
      }.bind(this),
      error: function(xhr, status, err) {
        console.error(this.props.url, status, err.toString())
      }.bind(this)
    })
  },
  getInitialState: function() {
    return {
        data: {weather: [{description: 'rainy'}]},
        city: 'london',
        country: 'uk'
    }
  },
  componentDidMount: function() {
    this.loadPhotosFromServer()
  },
  render: function() {
    return (
      <div>
        <h1>Weather</h1>
        <ExampleForm data={this.state.data} />
        <PhotoList data={this.state.data} />
        
      </div>
    )
  }
})

let PhotoList = React.createClass({
  render: function() {
    return (
      <div>
        {this.props.data.weather[0].description}
      </div>
    )
  }
})

let ExampleForm = React.createClass({
    getDefaultProps: function () {
        return {
            city: 'london',
            country: 'uk'
        }
    },
    getInitialState: function () {
        return {
            city: 'london',
            country: 'uk'
        }
    },
    onChange: function (event) {
        if (event.target.name == 'txtCity') {
            this.setState({
                city: event.target.value
            })
        } else {
            this.setState({
                country: event.target.value
            })
        }
    },
    // update method
    getWeather : function(){
        this.loadPhotosFromServer()
    },
    render: function () {
        return ( 
        <div>
            <input id='txtcity' name="txtCity"
                type='text'
                value={
                    this.state.city
                }
                onChange={
                    this.onChange
                }/>
            <input id='txtCountry' name="txtCountry"
                type='text'
                value={
                    this.state.country
                }
                onChange = {
                    this.onChange
                }/>
            <button 
                type="button" 
                id="btnSubmit"
                onClick={this.getWeather}>Get weather</button>
        </div>
        )
    }
})


ReactDOM.render(
    <div>
        <PhotoBox 
            url="http://api.openweathermap.org/data/2.5/weather"
            search="?q=dublin,ie"
            city="London" country="uk"
            ApiKey="&APPID=48f2d5e18b0d2bc50519b58cce6409f1" / >
    </div>, document.getElementById('content')
)
