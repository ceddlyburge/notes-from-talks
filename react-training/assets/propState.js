var ExampleForm = React.createClass({
    getInitialState: function () {
        return {
            message: 'Read and write'
        }
    },
    getDefaultProps: function () {
        return {
            message: 'Read only'
        }
    },
    onChange: function (event) {
        this.setState({
            message: event.target.value
        });
    },
    render: function () {
        return ( 
        <div>
            <input  id = 'readOnly'
                    type = 'text'
                    value = {
                        this.props.message
                    }
            /> 
            <input  id = 'readAndWrite'
                    type = 'text'
                    value = {
                        this.state.message
                    }
                    onChange = {
                        this.onChange
                    }/> 
        </div>
        );
    }
});
ReactDOM.render( <ExampleForm /> , document.getElementById('view'));