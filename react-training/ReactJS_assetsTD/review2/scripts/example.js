// see http://pastebin.com/bxGN4rwW
var Photo = React.createClass({
  render: function() {
    //  let temp = `data/gallery/${this.props.filename}.jpg`
    return (
      <div className="photo">
        <h2 className="photoAuthor">
            {this.props.filename}
        </h2>
        <h3>{this.props.photographer} {this.props.category}</h3>
        <img src={this.props.filename}/>
        <p>{this.props.description}</p>
      </div>
    );
  }
});

var PhotoBox = React.createClass({
  loadPhotosFromServer: function() {
    $.ajax({
      url: this.props.url,
      dataType: 'json',
      cache: false,
      success: function(data) {
        this.setState({data: data});
      }.bind(this),
      error: function(xhr, status, err) {
        console.error(this.props.url, status, err.toString());
      }.bind(this)
    });
  },
    
  getInitialState: function() {
    return {data: []};
  },
  componentDidMount: function() {
    this.loadPhotosFromServer();
  },
  render: function() {
    return (
      <div className="photoBox">
        <h1>Photos</h1>
        <PhotoList data={this.state.data} />
      </div>
    );
  }
});

var PhotoList = React.createClass({
  render: function() {
    var photoNodes = this.props.data.map(function(photo) {
      return (
        <Photo 
          filename={'data/gallery/'+photo.filename+'.jpg'} 
          category={photo.category}
          description={photo.desc} 
          photographer={photo.photographer}>
        </Photo>
      );
    });
    return (
      <div className="photoList">
        {photoNodes}
      </div>
    );
  }
});

ReactDOM.render(
  <PhotoBox url="data/photos.json"/>,
  document.getElementById('content')
);
