#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2012

include $(TOPDIR)/rules.mk

PKG_NAME:=mathomatic
PKG_VERSION:=16.0.5
PKG_RELEASE:=1

PKG_SOURCE:=mathomatic-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/mfillpot/mathomatic/archive
PKG_HASH:=d93fe35914dbbafa0e67000480268d7ca3e4de773b70f4130a6b3f4fbb20fae2

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/mathomatic
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libreadline +libncurses
	TITLE:=Small computer algebra system.
	URL:=http://www.mathomatic.org/math/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/mathomatic/description
 Mathomatic can symbolically solve, simplify, combine, and compare algebraic equations,
 simultaneously performing generalized standard, complex number, modular, and polynomial arithmetic, as needed.
endef

MAKE_VARS += \
	READLINE=1 \
	HANDHELD=1 \

TARGET_LDFLAGS += \
	-lreadline \
	-lncurses

define Package/mathomatic/install
	$(INSTALL_DIR) $(1)/opt/bin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/mathomatic $(1)/opt/bin/
endef

$(eval $(call BuildPackage,mathomatic))
