import React from 'react';

function DestinationList(props) {
  const items = props.items;
  const listItems = items.map((item) =>
    <div className="mt-6 w-full px-4 lg:w-1/2 xl:w-1/3">
      <div className="flex items-center rounded-lg bg-white shadow-lg overflow-hidden">
        <img className="h-32 w-32 flex-shrink-0" src={item.imgUrl} alt={item.imgAlt} />
        <div className="px-6 py-4">
          <h3 className="text-lg font-semibold text-gray-800">{item.name}</h3>
          <p className="text-gray-600">${item.price} / night average</p>
          <div className="mt-4">
            <a href="#" className="text-indigo-500 hover:text-indigo-400 font-semibold text-sm">
              Explore {item.propertyCount} properties
            </a>
          </div>
        </div>
      </div>
    </div>
  );

  return (
    <div className="bg-gray-300 p-2 pb-8">
      {listItems}
    </div>
  )
}

export { DestinationList };
