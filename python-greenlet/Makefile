#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Used by python-gevent only, no need to update

include $(TOPDIR)/rules.mk

PKG_NAME:=python-greenlet
PKG_VERSION:=0.4.15
PKG_RELEASE:=2

PYPI_NAME:=greenlet
PKG_HASH:=9416443e219356e3c31f1f918a91badf2e37acf297e2fa13d24d1cc2380f8fbc

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

# XXX error: option --single-version-externally-managed not recognized
PYTHON3_PKG_SETUP_ARGS:=

ifdef CONFIG_USE_MIPS16
  TARGET_CFLAGS += -mno-mips16 -mno-interlink-mips16
endif

define Package/python3-greenlet
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	TITLE:=lightweight in-process concurrent programming
	URL:=https://pypi.python.org/pypi/greenlet
	MAINTAINER:=Entware team, https://entware.net
	DEPENDS:=+python3-light
endef

define Package/python3-greenlet/description
 Lightweight in-process concurrent programming.
endef

$(eval $(call Py3Package,python3-greenlet))
$(eval $(call BuildPackage,python3-greenlet))
