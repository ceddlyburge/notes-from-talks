import React, { Component} from 'react';

// const List = () => (
//     <ul>
//     {
//         [1,2].map(i => <li>{i}</li>)
//     }
//     </ul>
// )

class List extends Component {
    constructor(props){
        super(props);
        this.state = {
            items: [1, 2, 3]
        }
    }

    addItem = () => {
        this.setState({
            itmes: [8]
        })
    }

    render() {
        return(
        <div>
        <button onClick={this.addItem}>Add Item</button>
        <ul>
        {
            this.state.items.map(i => <li>{i}</li>)
        }
        </ul>
        </div>)
    }
}
    

export default List;