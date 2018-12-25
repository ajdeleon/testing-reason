/* State declaration */
type state = {
  count: int,
  show: bool,
};

/* Action declaration */
type action =
  | Click
  | Toggle
  | Reset;

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("Example");

/* greeting and children are props. `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */
let make = (~greeting, _children) => {
  /* spread the other default fields of component here and override a few */
  ...component,
  initialState: () => {count: 69, show: true},
  /* State transitions */
  reducer: (action, state) =>
    switch (action) {
    | Click => ReasonReact.Update({...state, count: state.count + 1})
    | Toggle => ReasonReact.Update({...state, show: !state.show})
    | Reset => ReasonReact.Update({...state, count: 69})
    },
  render: self => {
    let message =
      "You've clicked this " ++ string_of_int(self.state.count) ++ " times(s)";
    <div>
      <button className="pa2 f3" onClick={_event => self.send(Click)}>
        {ReasonReact.string(message)}
      </button>
      <button className="f3 pa2 ml1 red" onClick={_e => self.send(Reset)}>
        {ReasonReact.string("RESET")}
      </button>
      <div>
        <button onClick={_event => self.send(Toggle)}>
          {ReasonReact.string("Toggle greeting")}
        </button>
      </div>
      {self.state.show ? ReasonReact.string(greeting) : ReasonReact.null}
    </div>;
  },
};
