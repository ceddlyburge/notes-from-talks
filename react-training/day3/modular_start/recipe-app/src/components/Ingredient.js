// declare the Ingredient module
const Ingredient = ({amount, measurement, name}) =>
    <li>
        <span className="amount">{amount}</span>
        <span>{measurement}</span>
        <span>{name}</span>
    </li>

// export default Ingredient
export default Ingredient