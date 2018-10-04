// import Ingredient
import Ingredient from './Ingredient'
// declare the IngredientsList module
const IngredientsList = ({list})=>
    <ul className="ingredients">
      {list.map((ingredient, i) => 
         <Ingredient key={i} {...ingredient} />)}
    </ul>

// export default IngredientsList
export default IngredientsList