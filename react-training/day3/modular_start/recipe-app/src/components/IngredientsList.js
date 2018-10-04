// import Ingredient
import Ingredient from './Ingredient'
// declare the IngredientsList module
const IngredientsList = ({ingredients}) =>
    <ul className="ingredients">
        {ingredients.map((ingredient, i) =>
            <Ingredient key={i} {...ingredient} />
        )}
    </ul>
// export default IngredientsList
export default IngredientsList