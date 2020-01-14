#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2010

include $(TOPDIR)/rules.mk

PKG_NAME:=python-cheetah
PKG_VERSION:=2.4.4
PKG_RELEASE:=2

PYPI_NAME:=Cheetah
PKG_HASH:=be308229f0c1e5e5af4f27d7ee06d90bb19e6af3059794e5fd536a6f29a9b550

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python-package.mk

define Package/python-cheetah
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	DEPENDS:=+python-setuptools
	TITLE:=Python-powered template engine
	URL:=http://www.cheetahtemplate.org/
	MAINTAINER:=Entware team, https://entware.net
	VARIANT:=python
endef

define Package/python-cheetah/description
 Cheetah is an open source template engine and code generation tool, written in
 Python. It can be used standalone or combined with other tools and frameworks.
 Web development is its principle use, but Cheetah is very flexible and is also
 being used to generate C++ game code, Java, sql, form emails and even Python
 code.
endef

$(eval $(call PyPackage,python-cheetah))
$(eval $(call BuildPackage,python-cheetah))
