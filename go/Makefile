#
# Copyright (C) 2011-2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=go
PKG_VERSION:=1.10
PKG_RELEASE:=1

PKG_SOURCE:=go$(PKG_VERSION).src.tar.gz
PKG_SOURCE_URL:=https://dl.google.com/go
PKG_BUILD_DIR:=$(BUILD_DIR)/go
PKG_HASH:=f3de49289405fda5fd1483a8fe6bd2fa5469e005fd567df64485c4fa000c7f24

OS=$(shell uname | tr 'A-Z' 'a-z')
bintype:=$(shell uname -m | sed \
	-e 's/i[3-9]86/386/' \
	-e 's/x86_64/amd64/' \
)

# Strip is not recommended for go binaries. It may make binaries unusable
STRIP:="/bin/true"

include $(INCLUDE_DIR)/package.mk

define Package/go
	SECTION:=lang
	CATEGORY:=Languages
	TITLE:=The Go Programming Language
	URL:=https://golang.org/
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/go/description
 Go is an open source programming language that makes it easy to build simple, reliable, and efficient software.
endef

define Build/Compile
	( \
		cd $(PKG_BUILD_DIR)/src; \
		CGO_ENABLED=0 GOOS=linux GOARCH=$(GOARCH) $(GOARM) $(GOMIPS) GOROOT_BOOTSTRAP=$(STAGING_DIR_HOST)/go ./make.bash --no-clean ; \
	)
	rm $(PKG_BUILD_DIR)/bin/go
	rm $(PKG_BUILD_DIR)/bin/gofmt
	mv $(PKG_BUILD_DIR)/bin/linux_$(GOARCH)/* $(PKG_BUILD_DIR)/bin/
	rm -rf $(PKG_BUILD_DIR)/bin/linux_$(GOARCH)
	rm -rf $(PKG_BUILD_DIR)/pkg/bootstrap
	rm -rf $(PKG_BUILD_DIR)/pkg/obj
	rm -rf $(PKG_BUILD_DIR)/pkg/$(OS)_$(bintype)
	rm -rf $(PKG_BUILD_DIR)/pkg/tool/$(OS)_$(bintype)
endef

define Package/go/postinst
#!/bin/sh
echo "Please add /opt/bin/go/bin to your PATH"
echo "Please set GOROOT=/opt/bin/go environment variable to use GO compiler"
endef

define Package/go/install
	$(INSTALL_DIR) $(1)/opt/bin/go
	$(CP) $(PKG_BUILD_DIR)/{api,bin,lib,misc,pkg,test,doc,src} $(1)/opt/bin/go
endef

$(eval $(call BuildPackage,go))
