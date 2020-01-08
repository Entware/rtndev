#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Used by python-gevent only, no need to update

include $(TOPDIR)/rules.mk

PKG_NAME:=python-greenlet
PKG_VERSION:=0.4.15
PKG_RELEASE:=1

PYPI_NAME:=greenlet
PKG_HASH:=9416443e219356e3c31f1f918a91badf2e37acf297e2fa13d24d1cc2380f8fbc

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python-package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/python-greenlet/Default
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	TITLE:=lightweight in-process concurrent programming
	URL:=https://pypi.python.org/pypi/greenlet
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/python-greenlet
$(call Package/python-greenlet/Default)
  DEPENDS:=+PACKAGE_python-greenlet:python-light
  VARIANT:=python
endef

define Package/python3-greenlet
$(call Package/python-greenlet/Default)
  DEPENDS:=+PACKAGE_python3-greenlet:python3-light
  VARIANT:=python3
endef

define Package/python-greenlet/description
 Lightweight in-process concurrent programming.
endef

define Package/python3-greenlet/description
$(call Package/python-greenlet/description)
.
(Variant for Python3).
endef

define PyBuild/Compile
	$(call Build/Compile/PyMod,,install --prefix=/opt --root=$(PKG_INSTALL_DIR))
endef

define Py3Build/Compile
	$(call Build/Compile/Py3Mod,,install --prefix=/opt --root=$(PKG_INSTALL_DIR))
endef

$(eval $(call PyPackage,python-greenlet))
$(eval $(call BuildPackage,python-greenlet))

$(eval $(call Py3Package,python3-greenlet))
$(eval $(call BuildPackage,python3-greenlet))
