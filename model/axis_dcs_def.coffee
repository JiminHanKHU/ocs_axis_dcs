module.exports =
  elements:
    axis_ctrl_pkg:
      elements:
        # axis
        axis_hw_adapter: {language: ['cpp'], build: 'obj', deploy: 'dist', codegen: true, active: true}
        axis_main_ctrl:  {language: ['cpp'], build: 'obj', deploy: 'dist', codegen: true, active: true}
        axis_ctrl_app:   {language: ['cpp'], build: 'app', deploy: 'dist', codegen: true, active: true}


