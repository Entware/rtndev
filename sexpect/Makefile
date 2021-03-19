#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=sexpect
PKG_VERSION:=2.3.4
PKG_REV:=1518ae3367f4111a02806373b99de76d3d5a6948
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/clarkwang/sexpect.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=1e6db9fe19c5cba325ea969987a5bad063a19f95f1b33d29ba3de1549053c232

include $(INCLUDE_DIR)/package.mk

define Package/sexpect
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Terminal
	TITLE:=another implementation of Expect
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/sexpect/description
 Unlike Expect (Tcl), Expect.pm (Perl), Pexpect (Python) or other similar
 Expect implementations, sexpect is not bound to any specific programming
 languages so it can be used with Shells (Bash, Ksh, Zsh, ...) and any
 other languages which support running external commands. Users who write
 shell scripts would love this because they don't have to learn other languages
 just to use the Expect feature.

 Another interesting sexpect feature is that the spawned child process is
 running in background. You can attach to and detach from it as needed.
endef

define Package/sexpect/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/sexpect $(1)/opt/bin
endef

$(eval $(call BuildPackage,sexpect))
