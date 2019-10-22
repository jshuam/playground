import React from 'react';
import ReactDOM from 'react-dom';
import './build/tailwind.css'
import { DestinationList } from './components/DestinationList';
import * as serviceWorker from './serviceWorker';

const destinations = [
    {
        name: 'Toronto',
        price: 120,
        propertyCount: 76,
        imgUrl: 'img/toronto.jpg',
        imgAlt: 'Toronto skyline'
    },
    {
        name: 'Sydney',
        price: 550,
        propertyCount: 256,
        imgUrl: 'img/sydney.jpg',
        imgAlt: 'Sydney Opera House'
    }
]

ReactDOM.render(<DestinationList items={destinations} />, document.getElementById('root'));

// If you want your app to work offline and load faster, you can change
// unregister() to register() below. Note this comes with some pitfalls.
// Learn more about service workers: https://bit.ly/CRA-PWA
serviceWorker.unregister();