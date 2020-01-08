#
# Copyright (C) 2008-2015 OpenWrt
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=characteristic
PKG_VERSION:=14.3.0
PKG_RELEASE:=1

PYPI_NAME:=$(PKG_NAME)
PKG_HASH:=ded68d4e424115ed44e5c83c2a901a0b6157a959079d7591d92106ffd3ada380

PKG_LICENSE:=MIT

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python-package.mk

define Package/python-characteristic
  SECTION:=lang
  CATEGORY:=Languages
  SUBMENU:=Python
  TITLE:=python-characteristic
  URL:=https://characteristic.readthedocs.org/
  DEPENDS:=+python
endef

define Package/python-characteristic/description
  characteristic is an MIT-licensed Python package with class decorators that ease the chores of implementing
  the most common attribute-related object protocols.
endef

define Build/Compile
	$(call Build/Compile/PyMod,,install --prefix=/opt --root=$(PKG_INSTALL_DIR))
endef

define Package/python-characteristic/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)
	$(CP) \
	    $(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/* \
	    $(1)$(PYTHON_PKG_DIR)
endef

$(eval $(call BuildPackage,python-characteristic))
