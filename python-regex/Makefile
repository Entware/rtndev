#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-regex
PKG_VERSION:=2020.1.7
PKG_RELEASE:=1

PYPI_NAME:=regex
PKG_HASH:=7391eeee49bb3ce895ca43479eaca810f0c2608556711fa02a82075768f81a37

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python-package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/python-regex/Default
  SECTION:=lang
  CATEGORY:=Languages
  SUBMENU:=Python
  TITLE:=python-regexp
  URL:=https://bitbucket.org/mrabarnett/mrab-regex
  MAINTAINER:=Entware team, https://entware.net
endef

define Package/python-regex
$(call Package/python-regex/Default)
  DEPENDS:=+PACKAGE_python-regex:python-light
  VARIANT:=python
endef

define Package/python3-regex
$(call Package/python-regex/Default)
  DEPENDS:=+PACKAGE_python3-regex:python3-light
  VARIANT:=python3
endef

define Package/python-regex/description
 This new regex implementation is intended eventually to replace Python’s current re module implementation. 
endef

define Package/python3-regex/description
$(call Package/python-regex/description)
.
(Variant for Python3).
endef

$(eval $(call PyPackage,python-regex))
$(eval $(call BuildPackage,python-regex))

$(eval $(call Py3Package,python3-regex))
$(eval $(call BuildPackage,python3-regex))
